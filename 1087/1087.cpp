#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
#define INF 99999999

using namespace std;
int e[201][201], weight[201], dis[201];
bool visit[201];
vector<int> pre[201], temppath, path;
map<string, int> m1;
map<int, string>m2;
int maxvalue = 0, mindepth = 0, cntpath = 0;
double maxavg;
int N, K;
void DFS(int v)
{
	temppath.push_back(v);
	if (v==1)
	{
		int value = 0;
		for (int i = 0; i < temppath.size(); i++)
		{
			value += weight[temppath[i]];				//记录当前权重
		}
		double tempavg = 1.0*value / (temppath.size() - 1);		//不算罗马城的
		if (value>maxvalue)
		{
			maxvalue = value; maxavg = tempavg; path = temppath;			//记录当前最大值了解一哈
		}
		else if (value==maxvalue&&tempavg>maxavg)
		{
			maxavg = tempavg; path = temppath;
		}
		temppath.pop_back();
		cntpath++;
		return;
	}
	for (int i = 0; i < pre[v].size(); i++)
	{
		DFS(pre[v][i]);
	}
	temppath.pop_back();
}

void solution()
{
	fill(e[0], e[0] + 201 * 201, INF);
	fill(dis, dis + 201, INF);
	cin >> N >> K;
	string str;
	cin >> str;
	m1[str] = 1;
	m2[1] = str;
	for (int i = 1; i < N; i++)
	{
		cin >> str >> weight[i + 1];
		m1[str] = i + 1;
		m2[i + 1] = str;			//存储映射关系
	}
	//input cost information
	string a, b;
	int temp;
	for (int i = 0; i < K; i++)
	{
		cin >> a >> b >> temp;
		if (temp < e[m1[a]][m1[b]])
		{
			e[m1[a]][m1[b]] = temp;
			e[m1[b]][m1[a]] = temp;
		}
	}
	//dij算法
	dis[1] = 0;
	for (int i = 0; i < N; i++)
	{
		int u = -1,mindis = INF;
		for (int j = 1; j <= N; j++)
		{
			if (visit[j]==false&&dis[j]<mindis)
			{
				u = j; mindis = dis[j];
			}
		}
		if (u == -1) break;
		visit[u] = true;
		for (int v = 1; v <= N; v++)
		{
			if (visit[v] == false && e[u][v] != INF)
			{													//dij
				if (dis[u] + e[u][v] < dis[v])
				{
					dis[v] = dis[u] + e[u][v];
					pre[v].clear();
					pre[v].push_back(u);						//记录可能的路径
				}
				else if (dis[v] == dis[u] + e[u][v])
				{
					pre[v].push_back(u);
				}
			}
		}
	}

	int rom = m1["ROM"];
	DFS(rom);
	cout << cntpath << ' ' << dis[rom] << ' ' << maxvalue << ' ' << (int)maxavg << endl;
	for (int i = path.size()-1; i >= 1; i--)
	{
		cout << m2[path[i]] << "->";
	}
	cout << "ROM";
	return;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}