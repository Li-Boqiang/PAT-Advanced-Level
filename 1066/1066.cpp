#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int N;
typedef struct tree
{
	int val;
	int height;
	struct tree *left;
	struct tree *right;
}Tree;

int HTree(Tree* root)						//求树的高度
{
	if (root == NULL)
		return -1;
	else
		return root->height;
}

Tree* SingleRotateWithLeft(Tree* r1)		//单左旋
{
	Tree* r2;
	r2 = r1->left;
	r1->left = r2->right;
	r2->right = r1;
	r1->height = max(HTree(r1->left), HTree(r1->right)) + 1;
	r2->height = max(HTree(r2->left), r1->height) + 1;
	return r2;
}

Tree* SingleRotateWithRight(Tree* r1)
{
	Tree* r2;
	r2 = r1->right;
	r1->right = r2->left;
	r2->left = r1;
	r1->height = max(HTree(r1->left), HTree(r1->right)) + 1;
	r2->height = max(r1->height, HTree(r2->right)) + 1;
	return r2;								//return the root
}
Tree* DoubleRotateWithLeft(Tree* root)		//对左子树先做单右旋转，再对根做左旋转
{
	root->left = SingleRotateWithRight(root->left);
	return SingleRotateWithLeft(root);
}
Tree* DoubleRotateWithRight(Tree* root)
{
	root->right = SingleRotateWithLeft(root->right);
	return SingleRotateWithRight(root);
}

Tree* AVLInsert(Tree* root, int num)
{
	if (root==NULL)
	{
		root = (Tree*)malloc(sizeof(Tree));
		root->val = num;
		root->height = 1;
		root->left = NULL;
		root->right = NULL;
	}
	else if (num < root->val)				//插入到左子树
	{
		root->left = AVLInsert(root->left, num);		//插入到左子树中
		if (HTree(root->left) - HTree(root->right) == 2)		//高度差为2表示需要调整
			if (num < root->left->val)
				root = SingleRotateWithLeft(root);
			else
				root = DoubleRotateWithLeft(root);
	}
	else if (num > root->val)
	{
		root->right = AVLInsert(root->right, num);
		if (HTree(root->right) - HTree(root->left) == 2)
			if (num > root->right->val)
				root = SingleRotateWithRight(root);
			else
				root = DoubleRotateWithRight(root);
	}
	root->height = max(HTree(root->left), HTree(root->right))+1;
	return root;
}
void solution()
{
	Tree* root = NULL;
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		root = AVLInsert(root, temp);
	}
	cout << root->val;
	return;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}