#include<iostream>
#include<queue>

#pragma warning(disable:4996)
using namespace std;

queue<int>que;
int T[10000];
bool visit[10000];
void build(int v)
{
	if (!que.empty())
	{
		int root = que.front(); que.pop();
		T[root] = v;
		visit[root] = true;
		que.push(2 * root);
		que.push(2 * root + 1);
	}
}

int M, N;
bool flag = true;
bool judgeMaxHeap(int root)
{
	if (visit[2*root] !=0&&flag)
	{
		flag = judgeMaxHeap(2 * root);
		if (flag)
			flag= T[root] > T[2*root];
	}
	if (visit[2*root+1] != NULL&&flag)
	{
		judgeMaxHeap(2 * root + 1);
		if (flag)
			flag= T[root] > T[2 * root + 1];
	}
	return flag;
}
bool judgeMinHeap(int root)
{
	
	if (visit[2 * root] != 0 && flag)
	{
		flag = judgeMinHeap(2 * root);
		if(flag)
			flag= T[root] < T[2 * root];
	}
	if (visit[2 * root + 1] != 0&&flag)
	{
		judgeMinHeap(2 * root + 1);
		if(flag)
			flag= T[root] < T[2 * root + 1];
	}
	return flag;
}
bool isFirst = true;
void postOrder(int root)
{
	if (visit[2*root] != 0)
		postOrder(2*root);
	if (visit[2 * root + 1] != 0)
		postOrder(2 * root + 1);
	if (!isFirst)
		cout << ' ' << T[root];
	else
	{
		cout << T[root];
		isFirst = false;
	}
}
void solution()
{
	int temp;
	cin >> M >> N;
	while (M--)
	{
		fill(visit, visit + 10000, 0);
		while (!que.empty())
			que.pop();
		que.push(1);
		for (int i = 1; i <= N; i++)
		{
			cin >> temp;
			build(temp);
		}
		flag = true;
		if (T[1] > T[2])
			if (judgeMaxHeap(1))
				cout << "Max Heap" << endl;
			else
				cout << "Not Heap" << endl;
		if(T[1] < T[2])
			if (judgeMinHeap(1))
				cout << "Min Heap" << endl;
			else
				cout << "Not Heap" << endl;
		isFirst = true;
		postOrder(1);
		cout << endl;
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}