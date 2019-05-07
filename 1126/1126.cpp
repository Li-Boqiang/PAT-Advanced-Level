#include<iostream>
#include<vector>

#pragma warning(disable:4996)
using namespace std;

int N, M;
int v1, v2;
int cnt = 0;
vector<vector<int>> G;
bool visit[501] = { 0 };
void DFS(int v)
{
	visit[v] = true;
	cnt++;
	for (int i = 0; i < G[v].size(); i++)
	{
		if (visit[G[v][i]] == false)
			DFS(G[v][i]);
	}
}
void solution()
{
	int cnt1 = 0;
	cin >> N >> M;
	G.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		cin >> v1 >> v2;
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}
	for (int i = 1; i <= N; i++)
	{
		cout << G[i].size();
		if (i != N)
			cout << ' ';
		if (G[i].size() % 2 != 0)
			cnt1++;
	}
	cout << endl;
	DFS(1);
	bool flag = false;
	if (cnt != N)
	{
		cout << "Non-Eulerian";
		return;
	}
	if (cnt1 == 0)
		cout << "Eulerian";
	else if (cnt1 == 2)
		cout << "Semi-Eulerian";
	else
		cout << "Non-Eulerian";
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}