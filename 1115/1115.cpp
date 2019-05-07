#include<iostream>
#include<queue>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
typedef struct
{
	int ID;
	int lchild, rchild;
}node;
node T[2010] = { 0 };
int num[1010], level[1010] = { 0 }, N;
queue<int> que;
bool cmp(int a, int b)
{
	return a > b;
}
void build(int x, int ID)
{
	int i;
	for (i = 1; T[i].ID != 0; )
	{
		if (x <= num[T[i].ID])
		{
			if (T[i].lchild == 0)
			{
				T[i].lchild = ID;
				i = ID;
			}
			else
				i = T[i].lchild;

		}
		else
		{
			if (T[i].rchild == 0)
			{
				T[i].rchild = ID;
				i = ID;
			}
			else
				i = T[i].rchild;
		}

	}
	T[i].ID = ID;
}
void solution()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
		build(num[i], i);
	}
	que.push(1);
	while (!que.empty())
	{
		int f = que.front(); que.pop();
		if (T[f].lchild != 0)
		{
			que.push(T[f].lchild);
			level[T[f].lchild] = level[f] + 1;
		}
		if (T[f].rchild != 0)
		{
			que.push(T[f].rchild);
			level[T[f].rchild] = level[f] + 1;
		}
	}
	sort(level, level + 1010, cmp);
	int n1 = 0, n2 = 0;
	for (int i = 0; i < N; i++)
	{
		if (level[i] == level[0])
			n1++;
		if (level[i] == (level[0] - 1))
			n2++;
	}
	cout << n1 << " + " << n2 << " = " << n1 + n2;

}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}