#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
typedef struct
{
	int weight;
	int rank;
}Mice;
typedef	struct
{
	int w;
	int id;
}node;
void solution()
{
	int np, ng;
	cin >> np >> ng;
	vector<Mice> M(np);
	vector<int>order(np);
	for (int i = 0; i < np; i++)
		cin >> M[i].weight;
	int num;
	for (int i = 0; i < np; i++)
		cin >> order[i];								//这个是初试的排序数组
	while (order.size() > 1)
	{
		vector<int>next;
		int currank = order.size() / ng + 1;
		if (order.size() % ng != 0)
			currank++;
		for (int i = 0; i < order.size()/ng; i++)		//这是一共多少个组
		{
			int maxw = -1, maxid = 0;
			for (int j = 0; j < ng; j++)
			{
				M[order[i*ng + j]].rank = currank;
				if (M[order[i*ng+j]].weight>maxw)
				{
					maxw = M[order[i*ng + j]].weight;
					maxid = order[i*ng + j];
				}
			}
			next.push_back(maxid);
		}
		if (order.size() % ng)								//这是处理剩下不到ng个的那部分
		{
			int maxw = -1, maxid = 0;
			for (int i = (order.size()/ng)*ng; i < order.size(); i++)
			{
				M[order[i]].rank = currank;
				if (M[order[i]].weight>maxw)
				{
					maxw = M[order[i]].weight;
					maxid = order[i];
				}
			}
			next.push_back(maxid);
		}
		order = next;
	}
	M[order[0]].rank = 1;							//最后一个是第一名
	for (int i = 0; i < M.size(); i++)
	{
		cout << M[i].rank;
		if (i != np - 1)
			cout << ' ';
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