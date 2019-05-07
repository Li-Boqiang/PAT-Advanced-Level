#include<iostream>
#include<vector>
#include<queue>
#pragma warning(disable:4996)
using namespace std;

typedef struct 
{
	int lchild=-1, rchild=-1;
}node;
vector<node> T;
vector<bool> FindRoot;
int N;
char temp1, temp2;
bool flag = false;
void InOrder(int root)
{
	if (T[root].rchild != -1)
		InOrder(T[root].rchild);
	if (flag)
		cout << ' ';
	cout << root;
	flag = true;
	if (T[root].lchild != -1)
		InOrder(T[root].lchild);
}
queue<int>que;
void levelOrder()
{
	while (!que.empty())
	{
		int root = que.front();
		que.pop();
		if (flag)
			cout << ' ';
		cout << root;
		flag = true;
		if (T[root].rchild != -1)
			que.push(T[root].rchild);
		if (T[root].lchild != -1)
			que.push(T[root].lchild);
	}
	cout << endl;
}
void solution()
{
	cin >> N;
	T.resize(N); FindRoot.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> temp1>>temp2;
		if (temp1 != '-')
		{
			T[i].lchild = temp1 - '0';
			FindRoot[temp1 - '0'] = true;
		}
		if (temp2 != '-')
		{
			T[i].rchild = temp2 - '0';
			FindRoot[temp2 - '0'] = true;
		}	
	}
	int root;
	for (int i = 0; i < N; i++)
	{
		if (FindRoot[i] == false)
		{
			root = i;
			break;
		}
	}
	flag = false;
	que.push(root);
	levelOrder();
	flag = false;
	InOrder(root);
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}