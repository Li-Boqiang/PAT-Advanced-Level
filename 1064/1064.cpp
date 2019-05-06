#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int node[1001], rebuild_tree[1001];
int N, pos = 0;
bool cmp(int a, int b)
{
	return a < b;
}
void creat_tree(int root)
{
	if (root>N)
	{
		return;
	}
	int lchild = root * 2, rchild = root * 2 + 1;
	creat_tree(lchild);
	rebuild_tree[root] = node[pos++];
	creat_tree(rchild);
}
void solution()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{	
		cin >> node[i];
	}
	sort(node, node + N, cmp);
	creat_tree(1);
	for (int i = 1; i <= N; i++)
	{
		cout << rebuild_tree[i];
		if (i<N)
		{
			cout << ' ';
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