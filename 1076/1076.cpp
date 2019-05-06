#include<iostream>
#include<vector>
#include<queue>
#pragma warning(disable:4996)
using namespace std;
vector <vector<int>> g;
typedef struct
{
	int id;
	int level;
}fans;
int N, L;
int BFS(fans follow)
{
	bool visit[1001] = {0};
	queue<fans> q;
	q.push(follow);
	visit[follow.id] = true;
	int cnt = 0;			//计数
	while (!q.empty())
	{
		follow = q.front();
		q.pop();
		for (int i = 0; i < g[follow.id].size(); i++)
		{
			int next_id = g[follow.id][i];
			if (!visit[next_id]&&follow.level<L)
			{
				q.push({ next_id,follow.level + 1 });		//把next_id压入队列中
				visit[next_id] = true;
				cnt++;
			}
		}
	}
	return cnt;
}
void solution()
{
	int M, input_id;
	cin >> N >> L;
	g.resize(N+1);
	for (int i = 1; i <= N; i++)
	{
		cin >> M;
		for (int j = 0; j < M; j++)
		{
			cin >> input_id;
			g[input_id].push_back(i);			//注意这里要反着写，因为M[i]是关注列表，即用户i是谁的粉丝。
		}
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> input_id;
		cout<<BFS({ input_id,0 })<<endl;
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}