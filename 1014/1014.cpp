//题目要点：进入黄线前是一个队列
//进入黄线后，每个窗口前面都是一个队列
//客户进入黄线后，不论别的队列发生了什么，均不得再改变队列

#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
struct node
{
	int FirstTime = 0;						//first表示服务完这个队列最前面的用户所用的时间
	int LastTime = 0;						//last表示服务完队列最后一个客户所用的时间
	queue<int> WaitList ;
};

struct 
{
	int NeedTime = 0;
	int WaitTime = 0;
} Customer[1001];

int n, m, k, q;
int WaitTime[1001] = { 0 };

void solution()
{
	cin >> n >> m >> k >> q;		//n是窗口数量，m是黄线内最大等待，k是客户的数量，q是要询问等待时间的客户数量
	for (int i = 1; i <= k; i++)
		cin >> Customer[i].NeedTime;			//输入等待的时间

	//如果k>n*m，则就要有人在黄线外面等待。
	int InsideNum;
	int WaitNum;
	if (k>m*n)
	{
		InsideNum = m*n;
		WaitNum = k-m*n;
	}
	else
	{
		InsideNum = k;
		WaitNum = 0;
	}

	//没上班的时候,预处理，可以认为是所有的客户在8点前统一到达
	vector<node> Window(21);			//用向量存储

	for (int i = 0; i < InsideNum; i++)
	{
		Window[i%n].WaitList.push(i+1);		//从0开始计算的
		Customer[i + 1].WaitTime = Window[i%n].LastTime;
		Window[i%n].LastTime += Customer[i + 1].NeedTime;
	}

	for (int j = 0; j < min(n,InsideNum); j++)
	{
		Window[j].FirstTime += Customer[Window[j].WaitList.front()].NeedTime;
		Window[j].WaitList.pop();
	}

	//准备好接客
	
	for (int i = 0; i < WaitNum; i++)
	{
		int flag = -1;
		int minn = 999999;						//初始设为无穷
		for (int j = 0; j < n; j++)
		{
			if (minn > Window[j].FirstTime)		//如果比最后一个要等的时间短，则赋值给minn
			{
				minn = Window[j].FirstTime;
				flag = j;
			}
		}
		Window[flag].FirstTime += Customer[Window[flag].WaitList.front()].NeedTime;		//第一个顾客服务完毕
		Window[flag].WaitList.pop();													//更新最前面的顾客等待值
		Window[flag].WaitList.push(n*m + i + 1);										//等待队列加一个人
		Customer[n*m + i + 1].WaitTime = Window[flag].LastTime;							//末尾等待时间获得
		Window[flag].LastTime += Customer[n*m + i + 1].NeedTime;						//加上去
	}

	for (int i = 0; i < q; i++)
	{
		int ask;
		cin >> ask;
		int LeaveTime=Customer[ask].WaitTime + Customer[ask].NeedTime;
		if (Customer[ask].WaitTime>=540)					//注意是大于等于
		{
			cout << "Sorry" << endl;

		}
		else
		{
			int OutputHour = 8 + LeaveTime / 60;
			if (OutputHour < 10)
				cout << '0' << OutputHour << ':';
			else
				cout << OutputHour << ':';
			int OutputMin = LeaveTime % 60;
			if (OutputMin < 10)
				cout << '0' << OutputMin << endl;
			else
				cout << OutputMin << endl;
		}
	}
}

int main()
{
	freopen("4.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}