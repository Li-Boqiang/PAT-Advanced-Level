#include<iostream>
#define MAXN 1000
#define MAX_VEC MAXN*MAXN
#pragma warning(disable:4996)

using namespace std;

struct Vec
{
	int from;
	int to;
} Vec[MAX_VEC];

int father[MAXN], siz[MAXN];

int GetFather(int x)		//得到所有节点所在树的根节点
{
	if (father[x]==x)		//如果这个节点的父节点是自身，这个树的根节点，返回x
		return x;
	else
		return father[x] = GetFather(father[x]);
}

void Union(int a, int b)
{
	int Father_a = GetFather(a);
	int Father_b = GetFather(b);
	if (Father_a!=Father_b)
	{
		if (siz[Father_a]<=siz[Father_b])
		{
			father[Father_a] = Father_b;
			siz[Father_b] += siz[Father_a];
		}
		else
		{
			father[Father_b] = Father_a;
			siz[Father_a] += siz[Father_b];
		}
	}
}


void solution()
{
	int n, m, k;					//k是要检查的城市的数量
	int cut;						//cut是被占领的城市

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)		//输入所有的边的信息，注意是由方向的
		cin >> Vec[i].from >> Vec[i].to;
	//下面将所有节点的集合信息初始化
	//各个顶点的根节点是他自己
	//各个顶点所形成的的集合的大小是1
	for (int i = 0; i < k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			father[j] = j;
			siz[j] = 1;
		}
		cin >> cut;

		//算法的核心。对于刚才输入进来的边，作以下处理：
		for (int j = 0; j < m; j++)
		{
			if (Vec[j].from==cut||Vec[j].to==cut)//如果这个边是由这个失陷的城市发出的，或者通往这个失陷的城市。							
			{
				continue;						//那么这个边，不予理会	
			}

			if (father[Vec[j].from]==father[Vec[j].to])//father数组存放的是这个大集合中，根节点所在的位置
			{											//如果这两个节点都在一个大集合中，即根节点是同一个节点
				continue;								//不予理会
			}
			Union(Vec[j].from, Vec[j].to);				//如果都不是，那么将两个集合并起来。

		}

		int cnt = 0;
		for (int j = 1; j <= n; j++)					//对于所有的城市进行一次遍历
		{				
			if (j!=cut&&father[j]==j)					//如果是被删除的城市，不予理会
			{							//如果这个节点所在集合的根节点是他自己（1.自己单成一个集合2,大集合中总有一个符合要求的点）
				cnt++;									//总的大集合数加一。
			}
		}
		
		cout << cnt - 1 << endl;						//连接三个大集合要两个线段，连接四个大集合要三个线段，所以是总数-1
	}

	
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}