//题目大意，给一个输入，如果这个输入是某二叉搜索树的前序遍历
//则打印yes，并输出这个二叉搜索树的后续遍历序列
//从一个前序便利中还原二叉树
#include<iostream>
#pragma warning(disable:4996)

using namespace std;

struct node
{
	node* LeftChild=NULL;
	node* RightChild=NULL;
	int value=0;
}Node[1010],MNode[1010];

int Num;
bool BST = true;
int j = 0;
bool Output = false;
void PreOrder(node* T)							
{
	if (T!=NULL)
	{
		if (T->value == Node[j].value)
			j++;
		else
		{
			BST = false;
			return;
		}
		PreOrder(T->LeftChild);
		PreOrder(T->RightChild);
		
	}
}


void PostOrder(node* T)							//后序是先左后右
{
	
	if (T!=NULL)
	{
		PostOrder(T->LeftChild);
		PostOrder(T->RightChild);
		if (!Output)
		{
			cout << T->value;
			Output = true;
		}
		else
		{
			cout << ' ' << T->value;
		}
		
	}
}


void solution()
{
	cin >> Num;
	node* p = &Node[0];
	cin >> Node[0].value;
	bool SetNode = false;
	for (int i = 1; i < Num; i++)
	{
		cin >> Node[i].value;
		SetNode = false;
		p = Node;
		while (!SetNode)
		{
			if (p->value>Node[i].value)				//要放到左子树
			{
				if (p->LeftChild == NULL)
				{
					p->LeftChild = &Node[i];
					SetNode = true;
					break;
				}
				else
				{
					p = p->LeftChild;
				}
			}
			else
			{
				if (p->RightChild==NULL)
				{
					p->RightChild = &Node[i];
					SetNode = true;
					break;
				}
				else
				{
					p = p->RightChild;
				}
			}
		}
		
	}

	PreOrder(Node);
	if (BST)
	{
		cout << "YES" << endl;
		PostOrder(Node);
	}
	else 
	{
		//看是不是镜像BST
		for (int i = 0; i < Num; i++)
		{
			node* temp;
			temp = Node[i].LeftChild;
			Node[i].LeftChild = Node[i].RightChild;
			Node[i].RightChild = temp;
		}

		BST = true;
		j = 0;

		PreOrder(Node);
		if (BST)
		{
			cout << "YES" << endl;
			PostOrder(Node);
		}
		else
			cout << "NO";
	}
}

int main()
{
	freopen("6.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}