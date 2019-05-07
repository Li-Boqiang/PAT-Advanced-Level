#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

//typedef struct node
//{
//	int data;
//	struct node* lchild,*rchild;
//};

typedef struct 
{
	int data;
	int lchild, rchild;
}node;
vector<node> T;
void build(int x, int y)
{
	
}

//void *build(node *&root, int v)
//{
//	if (root == NULL)
//	{
//		root = (node*)malloc(sizeof(node));
//		root->data = v;
//		root->lchild = root->rchild = NULL;
//	}
//	else if (abs(v) <= abs(root->data))
//		build(root->lchild, v);						//小的数在左子树
//	else
//		build(root->rchild, v);
//}
int K, N;
node *T = NULL;
//vector<int> info;
void solution()
{
	int temp;
	while (K--)
	{
		cin >> N;
		T.resize(N+1);
		for (int i = 1; i <= N; i++)
		{
			cin >> T[i].data;
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