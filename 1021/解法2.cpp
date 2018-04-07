#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

vector<vector<int>> v;//邻接表表示
bool visit[10005];
set<int> iset;
vector<int> deep_temp;//保存当前查询到的最深的
int deepest = 0;			//保存最大深度
int n;					//保存有多少对，即输入的N
void DFS(int root, int deep)
{
	if (deepest<deep)
	{
		deep_temp.clear();//全都清完
		deep_temp.push_back(root);//当前的节点加进去
		deepest = deep;
	}
	else if (deepest == deep)//深度一样
	{
		deep_temp.push_back(root);
	}
	visit[root] = true;
	for (int i = 0; i < v[root].size(); i++)
	{
		if (visit[v[root][i]] == false)//还没访问
		{
			DFS(v[root][i], deep + 1);//继续DFS
		}
	}
}



void solution()
{
	cin >> n;
	v.resize(n + 1);//最多n+1个节点
	int start, end, count = 0;		//count保存有多少棵树
	int newroot = 0;
	for (int i = 1; i < n; i++)			//注意，只有N-1个，如果写i=0，会case2段错误
	{
		cin >> start >> end;
		v[start].push_back(end);
		v[end].push_back(start);
	}
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == false)
		{
			DFS(i, 0);
			if (i == 1)
			{
				if (deep_temp.size() != 0)
				{
					newroot = deep_temp[0];//把第一个节点记下来
				}
				for (int j = 0; j < deep_temp.size(); j++)
				{
					iset.insert(deep_temp[j]);
				}
			}
			count++;
		}
	}
	if (count>1)
	{
		cout << "Error: " << count << " components";
	}
	else
	{
		//初始化
		deep_temp.clear();
		deepest = 0;
		fill(visit, visit + 10001, false);

		DFS(newroot, 0);
		for (int i = 0; i < deep_temp.size(); i++)
		{
			iset.insert(deep_temp[i]);
		}
		for (auto i = iset.begin(); i != iset.end(); i++)
		{
			cout << *i << endl;
		}
	}
	return;
}
int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}