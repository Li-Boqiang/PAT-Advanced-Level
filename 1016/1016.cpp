#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

typedef struct
{
	string TimeCall;		//表示时间
	bool OnOff;			//表示是挂还是拨打
	bool Real = false;
}Info;

map<string, vector<Info>> Cus;

int Cost[24];
int N;

bool comp(const Info& a,const Info& b)		//按拨打电话的顺序进行排序
{
	return a.TimeCall<b.TimeCall;
}

void solution()
{
	for (int i = 0; i < 24; i++)			//话费数组，其单位是美分/分钟
		cin >> Cost[i];
	cin >> N;
	string Name;
	string dadianhua;
	Info temp;
	for (int i = 0; i < N; i++)
	{
		cin >> Name;
		
		cin >> temp.TimeCall;
		cin >> dadianhua;
		if (dadianhua == "on-line")
			temp.OnOff = 1;
		else
			temp.OnOff = 0;
		Cus[Name].push_back(temp);
	}

	for (map<string, vector<Info>>::iterator iter = Cus.begin(); iter != Cus.end(); iter++)		//对每个分别排序
	{
		sort(iter->second.begin(), iter->second.end(), comp);
		for (vector<Info>::iterator iter2 = iter->second.begin(); iter2 != iter->second.end()-1; iter2++)
		{
			if (iter2->OnOff == 1 && (iter2 + 1)->OnOff == 0)									//只有10是一次正确的打电话，01，11,10都不算
			{
				(iter2 + 1)->Real = true;
				iter2->Real = true;
			}
		}
		for (vector<Info>::iterator i = iter->second.begin(); i < iter->second.end(); )
		{
			if (!i->Real)
				i=iter->second.erase(i);
			else
				i++;
		}
		int Month = 0, Day_start,Day_end, Hour_start, Hour_end, Mini_start, Mini_end;
		int huafei=0;
		int huafei_temp = 0;


		vector<Info>::iterator i_temp = iter->second.begin();
		if (i_temp==iter->second.end())												//如果不加这么一句，case2和case3错误，应该是题目写错了
			continue;
		cout << iter->first << ' ' << i_temp->TimeCall[0]<<i_temp->TimeCall[1] << endl;	//输出账单头
		for (vector<Info>::iterator i = iter->second.begin(); i < iter->second.end(); i++,i++)				//对这个人的账单进行遍历
		{
			Hour_start = (i->TimeCall[6] - '0') * 10 + (i->TimeCall[7] - '0');		//拨打电话的时间
			Hour_end = ((i + 1)->TimeCall[6] - '0') * 10 + ((i + 1)->TimeCall[7] - '0');	//挂电话的时间
			Mini_start= (i->TimeCall[9] - '0') * 10 + (i->TimeCall[10] - '0');		//拨打电话的时间
			Mini_end= ((i + 1)->TimeCall[9] - '0') * 10 + ((i + 1)->TimeCall[10] - '0');	//挂电话的时间

			Day_start= (i->TimeCall[3] - '0') * 10 + (i->TimeCall[4] - '0');		//拨打电话的时间
			Day_end= ((i + 1)->TimeCall[3] - '0') * 10 + ((i + 1)->TimeCall[4] - '0');	//挂电话的时间
			if (Day_end != Day_start)
				Hour_end += (Day_end - Day_start) * 24;

			if (Hour_end == Hour_start)												//不跨小时
			{
				huafei_temp += (Mini_end - Mini_start)*Cost[Hour_start];

			}
			else
			{																		//跨小时
				huafei_temp += (60 - Mini_start) * Cost[Hour_start];
				huafei_temp += (Mini_end)*Cost[Hour_end%24];
				for (int j = Hour_start; j < (Hour_end-1); j++)
					huafei_temp += 60 * Cost[(j + 1)%24];
			}
			for (int x = 3; x < 11; x++)
				cout << i->TimeCall[x];
			cout << ' ';
			for (int x = 3; x < 11; x++)
			{
				cout << (i + 1)->TimeCall[x];
			}
			cout << ' '<<(Hour_end-Hour_start)*60+(Mini_end-Mini_start)<<' ';
			cout << '$' << huafei_temp / 100 << '.';
			if (huafei_temp % 100 < 10)
				cout << '0' << huafei_temp % 10 << endl;
			else
				cout << huafei_temp % 100<<endl;
			huafei += huafei_temp;
			huafei_temp = 0;
		}
		cout<< "Total amount: $" << huafei / 100<<'.' ;
		if (huafei % 100 < 10)
			cout << '0' << huafei % 100 << endl;
		else
			cout << huafei % 100 << endl;
	}


}

int main()
{
	freopen("4.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}