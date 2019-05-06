#include<iostream>
#include<set>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
set<int> num[51];
int N, M, K;
void solution()
{
	cin >> K;
	int set1, set2;
	int cnt;//计数有多少个相同的数字
	for (int i = 0; i < K; i++)
	{
		cnt = 0;
		cin >> set1 >> set2;
		if (num[set1].size() < num[set2].size())
		{
			for (auto it = num[set1].begin(); it != num[set1].end(); it++)
			{
				if (num[set2].count(*it))
					cnt++;
			}
		}
		else
		{
			for (auto it = num[set2].begin(); it != num[set2].end(); it++)
			{
				if (num[set1].count(*it))
					cnt++;
			}
		}
		//float temp = cnt*100.0 / (num[set1].size() + num[set2].size() - cnt);
		printf("%.1f%%\n", cnt*100.0 / (num[set1].size() + num[set2].size() - cnt));
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> M;
		for (int j = 0; j < M; j++)
		{
			cin >> temp;
			num[i + 1].insert(temp);
		}
	}
	solution();
	system("pause");
	return 0;
}