#include<iostream>
#include<stack>
#include<queue>
#pragma warning(disable:4996)
using namespace std;

typedef struct tree
{
	int value;
	struct tree *lchild;
	struct tree *rchild;
}Tree;
Tree *T;
int N, post[31], in[31], level[99999999] = { 0 };					//其实这里是不严谨的
stack<Tree*>sta;
queue<Tree*>que;


void build(int root, int start, int end, Tree* &r)
{
	if (start > end)
		return;
	int i = start;
	while (i < end&&in[i] != post[root])			//不断查找根节点
		i++;
	r = (Tree*)malloc(sizeof(Tree));
	r->value = post[root];
	r->lchild = NULL;
	r->rchild = NULL;
	//level[index] = post[root];
	build(root - 1 - end + i, start, i - 1, r->lchild);
	build(root - 1, i + 1, end, r->rchild);
}



void solution()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> in[i];
	for (int i = 0; i < N; i++)
		cin >> post[i];
	build(N - 1, 0, N - 1, T);
	sta.push(T);
	bool flag = false;
	Tree* f;int cnt = N;
	stack<Tree*>temp;
	while (cnt)
	{
		while (!sta.empty())
		{
			f = sta.top();
			sta.pop();
			if (flag)
				cout << ' ';
			cout << f->value;
			cnt--;
			flag = true;
			temp.push(f);
		}
		while (!temp.empty())
		{
			f = temp.top();
			temp.pop();
			if (f->lchild!=NULL)
				que.push(f->lchild);
			if (f->rchild != NULL)
				que.push(f->rchild);
		}
		while (!que.empty())
		{
			f = que.front(); que.pop();
			if (flag)
				cout << ' ';
			cout << f->value;
			cnt--;
			flag = true;
			if (f->lchild != NULL)
				sta.push(f->lchild );
			if (f->rchild != NULL)
				sta.push(f->rchild);
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