#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#pragma warning(disable:4996)
using namespace std;

typedef struct 
{
	int value;
	int lchild, rchild;
}node;
vector<node> BT;
vector<int>num;
int N, l, r, cnt = 0;
void insert(int root)
{
	if (BT[root].lchild != -1)
		insert(BT[root].lchild);
	BT[root].value = num[cnt++];
	if (BT[root].rchild != -1)
		insert(BT[root].rchild);
}
queue<int> que;
bool flag = false;
void bianli()
{
	while (!que.empty())
	{
		if (flag)
			cout << ' ' << BT[que.front()].value;
		else
		{
			cout << BT[que.front()].value;
			flag = true;
		}
		if (BT[que.front()].lchild!=-1)
			que.push(BT[que.front()].lchild);
		if(BT[que.front()].rchild!=-1)
			que.push(BT[que.front()].rchild);
		que.pop();
	}
}
void solution()
{
	cin >> N;
	BT.resize(N); num.resize(N);
	for (int i = 0; i < N; i++)
		cin >> BT[i].lchild >> BT[i].rchild;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	sort(num.begin(), num.end());
	insert(0);
	que.push(0);
	bianli();
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}