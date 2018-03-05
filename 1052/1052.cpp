//这个题目的坑在于，所给的信息中，有的节点并不在这个链表里
#include<iostream>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;

struct node
{
	string Address;
	int Key;
	string Next;
	bool flag;
}Node[10001];

bool comp(node a, node b)
{
	if (a.flag==false||b.flag==false)
	{
		return a.flag > b.flag;
	}
	else
		return a.Key < b.Key;
}
void solution()
{
	int N, Head;
	cin >> N >> Head;
	for (int i = 0; i < N; i++)
	{
		cin >> Node[i].Address >> Node[i].Key >> Node[i].Next;
	}
	for (int i = Head; i != -1; i++)
	{

	}
	sort(Node, Node + N,comp);
	cout << N <<' '<< Node[0].Address << endl;
	for (int i = 0; i < N-1; i++)
	{
		cout << Node[i].Address << ' ' << Node[i].Key << ' ' << Node[i + 1].Address << endl;
	}
	cout << Node[N - 1].Address << ' ' << Node[N - 1].Key << ' ' << "-1";
}

int main(void)
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}