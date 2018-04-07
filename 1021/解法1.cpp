#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

vector<int>node;
set<int>resset;
vector<vector<int>>v;//邻接表表示
vector<int>nodeDeep;//保存每个节点的深度
vector<bool> visit;
int n;

//并查集
int getParent(int x)
{
	if (node[x] != x)
		return node[x] = getParent(node[x]);
	else
		return x;
}
//合并
void unite(int x, int y)
{
	x = getParent(x);
	y = getParent(y);
	if (x > y)
		node[y] = x;
	else
		node[x] = y;
}


int deepest = 0;
void DFS(int root, int deep)
{
	nodeDeep[root] = deep;
	visit[root] = true;//标记为访问
	if (deepest < deep)
		deepest = deep;
	for (int i = 0; i < v[root].size(); i++)
	{
		if (!visit[v[root][i]])
		{
			DFS(v[root][i], deep + 1);
		}
	}
}


void solution()
{
	int start;
	int end;
	cin >> n;
	v.resize(n + 1);
	node.resize(n + 1);
	nodeDeep.resize(n + 1);
	visit.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		node[i] = i;
	for (int i = 1; i < n; i++)
	{
		cin >> start >> end;
		v[start].push_back(end);
		v[end].push_back(start);
		unite(start, end);
	}

	//判断有几个集合
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (node[i] == i)
			++count;
	}
	if (count>1)
	{
		cout << "Error: " << count << " components";
		return;
	}
	DFS(1, 1);

	for (int i = 1; i <= n; i++)
	{
		if (nodeDeep[i] == deepest)
		{
			resset.insert(i);
		}
	}
	visit.clear();
	visit.resize(n + 1, 0);
	deepest = 0;
	int newroot = *resset.begin();
	DFS(newroot, 1);
	for (int i = 1; i <= n; i++)
	{
		if (nodeDeep[i] == deepest)
		{
			resset.insert(i);
		}
	}
	for (auto i = resset.begin(); i != resset.end(); i++)
	{
		cout << *i << endl;
	}

	return;
}
int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
