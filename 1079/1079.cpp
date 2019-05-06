#include<iostream>
#include<vector>
#include<cmath>
#pragma warning(disable:4996)
using namespace std;
vector<int> buy;				//表示零售商卖出去多少
vector<vector<int>>G;
int N;
double r, P, res=0.0;

void DFS(int num, int step)
{
	int end = 1;
	for (int i = 0; i < G[num].size(); i++)
	{
		int v = G[num][i];
		end = 0;
		DFS(v, step + 1);
	}
	if (end)
	{
		res += P*(pow((1 + r*0.01), step)*buy[num]);
	}
}

void solution()
{
	cin >> N;
	cin >> P >> r;
	G.resize(N);
	buy.resize(N);
	int a,b;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			cin >> b;
			G[i].push_back(b);		//b是a的下家
		}
		if (a == 0)
		{
			cin >> b;
			buy[i] = b;
		}
	}
	DFS(0, 0);
	printf("%.1f\n", res);
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}