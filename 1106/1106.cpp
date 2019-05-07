#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#pragma warning(disable:4996)
using namespace std;

int N, K, temp, cnt = 0, MinLevel=999999;
double P, r;
int level[100011] = { 0 };
vector<vector<int>>T;
void solution()
{
	cin >> N >> P >> r;
	T.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> K;
		T[i].resize(K);
		for (int j = 0; j < K; j++)
			cin >> T[i][j];
	}
	queue<int> que;	que.push(0);
	while (!que.empty())
	{
		temp = que.front(); que.pop();
		if (T[temp].size() == 0)
		{
			if (MinLevel > level[temp])
			{
				MinLevel = level[temp];
				cnt = 1;
			}
			else if (MinLevel == level[temp])
				cnt++;
		}
		for (int i = 0; i < T[temp].size(); i++)
		{
			que.push(T[temp][i]);
			level[T[temp][i]] = level[temp] + 1;
		}
	}
	printf("%.4f ", P*pow(1 + r / 100, MinLevel));
	cout << cnt;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}