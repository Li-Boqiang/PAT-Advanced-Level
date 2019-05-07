#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

int N, K, kaishi;
typedef struct 
{
	int addr;
	int data;
	int NextAddr;
}node;
vector<node> Link1, Link2, Link3, info;
int dizhi, shuju, xiayige;
void solution()
{
	cin >> kaishi >> N >> K;
	info.resize(100001);
	int v;
	for (int i = 0; i < N; i++)
	{
		cin >> dizhi >> shuju >> xiayige;
		info[dizhi]={ dizhi,shuju,xiayige };
	}
	for (int i = kaishi; i != -1; i=info[i].NextAddr)
	{
		if (info[i].data < 0)
			Link1.push_back(info[i]);
		else if (info[i].data <= K)
			Link2.push_back(info[i]);
		else
			Link3.push_back(info[i]);
	}
	bool flag=false;
	if (Link1.size() > 0)
	{
		for (int i = 0; i < Link1.size() - 1; i++)
			printf("%05d %d %05d\n", Link1[i].addr, Link1[i].data, Link1[i + 1].addr);
		printf("%05d %d ", Link1[Link1.size() - 1].addr, Link1[Link1.size() - 1].data);
		flag = true;
	}
	if (Link2.size() > 0)
	{
		if(flag)
			printf("%05d\n", Link2[0].addr);
		for (int i = 0; i < Link2.size() - 1; i++)
			printf("%05d %d %05d\n", Link2[i].addr, Link2[i].data, Link2[i + 1].addr);
		printf("%05d %d ", Link2[Link2.size() - 1].addr, Link2[Link2.size() - 1].data);
		flag = true;
	}
	if (Link3.size()>0)
	{
		if (flag)
			printf("%05d\n", Link3[0].addr);
		for (int i = 0; i < Link3.size() - 1; i++)
			printf("%05d %d %05d\n", Link3[i].addr, Link3[i].data, Link3[i + 1].addr);
		printf("%05d %d ", Link3[Link3.size() - 1].addr, Link3[Link3.size() - 1].data);
	}
	cout << -1;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}