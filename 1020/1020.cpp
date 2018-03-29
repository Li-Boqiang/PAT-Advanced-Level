#include<iostream>
#include<vector>
#pragma warning(disable:4996)

using namespace std;
vector<int> post, in, level(100000, -1);
//level用于存放二叉树，这里采用二叉树的线性表存储方法，这样的话，简单，而且也能很直观的进行层次遍历。
void pre(int root, int start, int end, int index)
{
	if (start > end)
		return;
	int i = start;
	while (i < end&&in[i] != post[root])
		i++;
	level[index] = post[root];
	pre(root - 1 - end + i, start, i - 1, 2 * index + 1);
	pre(root-1, i + 1, end, 2 * index + 2);
}
void solution()
{
	//total用于存储第一个值，即有多少个数字
	//isFirst用于标记是否输出过数字
	int total, isFirst = false;
	cin >> total;
	in.resize(total);
	post.resize(total);
	for (int i = 0; i < total; i++)
	{
		cin >> post[i];
	}
	for (int i = 0; i < total; i++)
	{
		cin >> in[i];
	}


	//构建二叉树
	pre(total - 1, 0, total - 1, 0);


	for (int i = 0; i < level.size(); i++)
	{
		if (level[i] != -1)
		{
			if (isFirst)
				cout << ' ';
			cout << level[i];
			isFirst++;
		}
		if (isFirst == total)
			return;
	}

}
int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}