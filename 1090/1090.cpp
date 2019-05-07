#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<math.h>
#pragma warning(disable:4996)
using namespace std;

int N;
double P, r;
vector<vector<int>>M;			//存储整个销售网络
vector<int> level;
//int level[100011] = { 0 };
bool cmp(int a, int b)
{
	return a > b;
}
void solution()
{
	cin >> N >> P >> r;
	int temp;
	M.resize(N + 1);
	level.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		M[temp + 1].push_back(i);
	}
	queue<int> que;	que.push(0);
	
	while (!que.empty())
	{
		temp = que.front(); que.pop();
		for (int i = 0; i < M[temp].size(); i++)
		{
			que.push(M[temp][i]);
			level[M[temp][i]] = level[temp] + 1;
		}
	}
	sort(level.begin(), level.end(), cmp);
	temp = level[0];
	printf("%.2f ", P*pow(1 + r / 100, temp - 1));
	//cout << P*pow(1 + r / 100, temp-1) << ' ';
	int cnt = 0;
	while (level[cnt]==temp)
	{
		cnt++;
	}
	cout << cnt;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}