#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#pragma warning(disable:4996)
using namespace std;

int N, M;
int id, k, temp;
queue<int> que;
vector<int> level;
void solution()
{
	cin >> N >> M;
	vector<vector<int>> T;
	T.resize(N+1);
	for (int i = 0; i < M; i++)
	{
		cin >> id >> k;
		T[id].resize(k);
		for (int j = 0; j < k; j++)
		{
			cin >> temp;
			T[id][j] = temp;
		}
	}
	level.resize(N+1);
	level[1] = 1;
	que.push(1);
	while (!que.empty())
	{
		id = que.front(); que.pop();
		for (int i = 0; i < T[id].size(); i++)
		{
			que.push(T[id][i]);
			level[T[id][i]] = level[id] + 1;
		}
	}
	vector<int> cnt; cnt.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cnt[level[i]]++;
	}
	level = cnt;
	sort(cnt.begin(), cnt.end());
	cout << cnt[N] << ' ';
	for (int i = 1; i <= N; i++)
	{
		if (level[i] == cnt[N])
		{
			cout << i;
			break;
		}
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}	 