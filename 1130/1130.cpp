#include<iostream>
#include<vector>
#include<string>
#pragma warning(disable:4996)
using namespace std;
int N;
typedef struct 
{
	string data;
	int lchild;
	int rchild;
}node;
vector<node>v;
bool findroot[21] = { 0 };

bool isLeaf(int t)
{
	return v[t].lchild == -1 && v[t].rchild == -1;
}

void DFS(int root)
{
	if (v[root].lchild!=-1)
	{
		if (!isLeaf(v[root].lchild))
			cout << '(';
		else
			cout << "";
		DFS(v[root].lchild);
		if (!isLeaf(v[root].lchild))
			cout << ')';
		else
			cout << "";
	}
	cout << v[root].data;
	if (v[root].rchild!=-1)
	{
		if (!isLeaf(v[root].rchild))
			cout << '(';
		else
			cout << "";
		DFS(v[root].rchild);
		if (!isLeaf(v[root].rchild))
			cout << ')';
		else
			cout << "";
	}
}

void solution()
{
	cin >> N;
	v.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> v[i].data >> v[i].lchild >> v[i].rchild;
		if (v[i].lchild != -1)
			findroot[v[i].lchild] = true;
		if (v[i].rchild != -1)
			findroot[v[i].rchild] = true;
	}
	int i;
	for ( i = 1; i <= N; i++)
	{
		if (findroot[i] == false)
			break;
	}
	DFS(i);
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}