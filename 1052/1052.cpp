#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
typedef struct node
{
	int addr;
	int next;
	int key;
	bool isLinked=false;
}Node;
int N, startaddr;
vector<Node>LinkList(100001);

bool cmp(Node a, Node b)
{
	if (!a.isLinked || !b.isLinked)				//两个全都在的话，判断结果为0，需要进行键值的比较
		return a.isLinked > b.isLinked;
	else
		return
		a.key < b.key;
}
void solution()
{
	int NodeNumber = 0;
	for (int i = startaddr; i !=-1 ; i=LinkList[i].next)
	{
		LinkList[i].isLinked = true;
		NodeNumber++;
	}
	if (NodeNumber == 0)
	{
		cout << "0 -1";
		return;
	}

	sort(LinkList.begin(), LinkList.end(), cmp);
	printf("%d %05d\n", NodeNumber, LinkList[0].addr);
	for (int i = 0; i < NodeNumber-1; i++)
	{
		printf("%05d %d %05d\n", LinkList[i].addr, LinkList[i].key, LinkList[i + 1].addr);
	}
	printf("%05d %d -1", LinkList[NodeNumber - 1].addr, LinkList[NodeNumber - 1].key);
	return;
}

int main()
{
	freopen("1.txt", "r", stdin);
	cin >> N >> startaddr;
	int addr;
	for (int i = 0; i < N; i++)
	{
		cin >> addr;
		LinkList[addr].addr = addr;
		cin >> LinkList[addr].key >> LinkList[addr].next;
	}
	solution();
	system("pause");
	return 0;
}