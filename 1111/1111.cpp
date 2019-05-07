#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
#define INF 99999999
using namespace std;

typedef struct 
{
	int l;
	int t;
} node;
int N, M, OneWay, len, t_cost, v1, v2, kaishi, jieshu, dis[501];
int Gdis[501][501], Gcost[501][501];
int mindis=INF, mincost = INF,costvalue;
vector<int> disres, costres, distemp, costtemp;
vector<int>pre[501];

void DFS(int v)
{
	distemp.push_back(v);
	if (v==kaishi)
	{
		costvalue = 0;
		for (int i = 0; i < distemp.size() - 1; i++)
		{
			costvalue += Gcost[distemp[i + 1]][distemp[i]];
		}
		if (mincost>costvalue)
		{
			mincost = costvalue;
			disres = distemp;
		}
		distemp.pop_back();
		return;
	}
	for (int i = 0; i < pre[v].size(); i++)
	{
		DFS(pre[v][i]);
	}
	distemp.pop_back();
}

void DFS2(int v)
{
	costtemp.push_back(v);
	if (v == kaishi)
	{
		if (costtemp.size()<mindis)
		{
			mindis = costtemp.size();
			costres = costtemp;
		}
		costtemp.pop_back();
		return;
	}
	for (int i = 0; i < pre[v].size(); i++)
	{
		DFS2(pre[v][i]);
	}
	costtemp.pop_back();
}


void dij(int G[501][501])
{
	for (int i = 0; i < 501; i++)
		pre[i].clear();
	fill(dis, dis + 501, INF);
	bool visit[501] = { 0 };
	dis[kaishi] = 0;
	for (int i = 0; i < N; i++)
	{
		int u = -1, mindis = INF;
		for (int j = 0; j < N; j++)
		{
			if (visit[j] == false && dis[j] < mindis)
			{
				u = j;
				mindis = dis[j];
			}
		}
		if (u == -1)
			break;
		visit[u] = true;
		for (int v = 0; v < N; v++)
		{
			if (visit[v]==false&&G[u][v]!=INF)
			{
				if (dis[u] + G[u][v] < dis[v])
				{
					dis[v] = dis[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (dis[u] + G[u][v] == dis[v])
					pre[v].push_back(u);
			}
		}
	}	
}

void solution()
{
	cin >> N >> M;
	fill(Gdis[0], Gdis[0] + 501 * 501, INF);
	fill(Gcost[0], Gcost[0] + 501 * 501, INF);
	for (int i = 0; i < M; i++)
	{
		cin >> v1 >> v2 >> OneWay >> len >> t_cost;
		if (OneWay)
		{
			Gdis[v1][v2] = len;
			Gcost[v1][v2] = t_cost;
		}
		else
		{
			Gdis[v1][v2] = len;
			Gcost[v1][v2] = t_cost;
			Gdis[v2][v1] = len;
			Gcost[v2][v1] = t_cost;
		}
	}
	cin >> kaishi >> jieshu;
	dij(Gdis);
	DFS(jieshu);
	int temp1 = dis[jieshu];
	dij(Gcost);
	DFS2(jieshu);
	int temp2 = dis[jieshu];
	if (disres!=costres)
	{
		cout << "Distance = " << temp1 << ": ";
		for (int i = disres.size() - 1; i >= 0; i--)
		{
			cout << disres[i];
			if (i != 0)
				cout << " -> ";
		}
		cout << endl;
		cout << "Time = " << temp2 << ": ";
		for (int i = costres.size() - 1; i >= 0; i--)
		{
			cout << costres[i];
			if (i != 0)
				cout << " -> ";
		}
	}
	else
	{
		cout << "Distance = " << temp1 << "; Time = " << temp2 << ": ";
		for (int i = disres.size() - 1; i >= 0; i--)
		{
			cout << disres[i];
			if (i != 0)
				cout << " -> ";
		}
	}
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}