//模拟队列

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#pragma warning(disable:4996)

using namespace std;
int N, K;							//N是客户的数量，K是窗口的数量



struct node
{
	string ArriveTime;				//到达的时间
	int NeedTime;					//所需服务的时间	
	int ArriveTime_Sec;				//到达的时间，以秒算	
	int GetServeTime;				//得到服务的时间。
	int WaitTime=0;
}Customer[10005];

bool comp(node a, node b)
{
	return a.ArriveTime_Sec < b.ArriveTime_Sec;
}
int Window[105] = {0};				//保存最近可以使用的时间

void solution()
{
	//int Served = 1;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> Customer[i].ArriveTime >> Customer[i].NeedTime;
		Customer[i].ArriveTime_Sec = (Customer[i].ArriveTime[0] - '0') * 10 * 60 * 60 + (Customer[i].ArriveTime[1] - '0') * 60 * 60 +
			(Customer[i].ArriveTime[3] - '0') * 10 * 60 + (Customer[i].ArriveTime[4] - '0') * 60 +
			(Customer[i].ArriveTime[6] - '0') * 10 + (Customer[i].ArriveTime[7] - '0');
		/*if (Customer[i].ArriveTime_Sec < 8 * 60 * 60)
			Customer[i].ArriveTime_Sec = 8 * 60 * 60;*/
	}
	sort(Customer, Customer + N, comp);
	for (int i = 0; i < K; i++)		//初始化
		Window[i] = 8 * 60 * 60;
	int MinWindow,Mintime;
	for (int i = 0; i < N; i++)
	{
		Mintime = 999999999;				//一开始以为这个银行不会敬业到通晓干活，就设置的初值为24*3600，结果发现最后一个样例过不去。真·敬业！
		for (int j = 0; j < K; j++)			//选出当前最快可以使用的窗口
		{
			if (Mintime>Window[j])		
			{
				Mintime = Window[j];
				MinWindow = j;
			}
		}
		if (Customer[i].ArriveTime_Sec > 17 * 3600)			
		{
			//Served = i;
			N = i;										//用于记录实际服务了多少人
			break;
		}

		if (Customer[i].ArriveTime_Sec<Mintime)			//需要等待
		{
			Customer[i].GetServeTime = Mintime;
			Customer[i].WaitTime = Mintime - Customer[i].ArriveTime_Sec;
			Window[MinWindow] = Mintime + Customer[i].NeedTime*60;			//更新释放时间
		}
		else
		{
			Customer[i].GetServeTime = Customer[i].ArriveTime_Sec;		//不需要等待
			Customer[i].WaitTime = 0;
			Window[MinWindow] = Customer[i].ArriveTime_Sec + Customer[i].NeedTime*60;			//更新释放时间
		}
	}
	float TotalTime=0;
	if (N == 0)
		N = 1;
	for (int i = 0; i < N; i++)
		TotalTime += Customer[i].WaitTime;
	cout << fixed << setprecision(1) << TotalTime / 60.0 / N << endl;
}


int main()
{
	freopen("3.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}