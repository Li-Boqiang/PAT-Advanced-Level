#include<iostream>
#include <algorithm>
#include <cstdio>
#pragma warning(disable:4996)
using namespace std;

typedef struct
{
	int key;
	int next;
	int id;
}node;

node saveLink[100001],deleLink[100001],inputLink[100001];
bool flag[10001] = { 0 };
int N, addr, first;
void solution()
{
	cin >> first >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> addr;
		cin >> inputLink[addr].key >> inputLink[addr].next;
		inputLink[addr].id = addr;
	}
	int save=0,dele=0;
	for (int i = first; i!=-1; i=inputLink[i].next)
	{
		if (!flag[abs(inputLink[i].key)])
		{
			saveLink[save++] = inputLink[i];
			flag[abs(inputLink[i].key)] = true;
		}
		else
		{
			deleLink[dele++] = inputLink[i];
		}
	}
	for (int i = 0; i < save-1; i++)
	{
		printf("%05d %d %05d\n", saveLink[i].id, saveLink[i].key, saveLink[i + 1].id);
	}
	printf("%05d %d -1\n", saveLink[save - 1].id, saveLink[save - 1].key);
	for (int i = 0; i < dele-1; i++)
	{
		printf("%05d %d %05d\n", deleLink[i].id, deleLink[i].key, deleLink[i + 1].id);
	}
	if(dele>0)
		printf("%05d %d -1\n", deleLink[dele - 1].id, deleLink[dele - 1].key);
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}