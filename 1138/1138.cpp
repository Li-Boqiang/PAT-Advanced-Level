#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
vector<int> pre, in;
int N;
bool flag = false;
void build(int root, int start, int end)
{
	if (start > end||flag)
		return;
	int i = start;
	while (i < end&&in[i] != pre[root])			//不断查找根节点在中序中的位置，i表示位置
		i++;
	if(!flag)
		build(root + 1, start, i - 1);
	if(!flag)
		build(root + i -start+ 1, i + 1, end);
	if (start == end&&flag == false)
	{
		cout << pre[root];
		flag = true;
	}
	return;
}


void solution()
{
	cin >> N;
	pre.resize(N);
	in.resize(N);
	for (int i = 0; i < N; i++)
		cin >> pre[i];
	for (int i = 0; i < N; i++)
		cin >> in[i];
	build(0, 0, N - 1);
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}