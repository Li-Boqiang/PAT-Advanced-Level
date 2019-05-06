#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int first, k, n;
int LinkData[100001];
int LinkNext[100001];
vector<int> L;
void solution()
{
	cin >> first >> n >> k;
	int addr, node_data, next_addr;
	for (int i = 0; i < n; i++)
	{
		cin >> addr >> node_data >> next_addr;
		LinkData[addr] = node_data;
		LinkNext[addr] = next_addr;
	}
	for (int i = first; i != -1; i = LinkNext[i])
	{
		L.push_back(i);
	}
	int length = L.size();
	for (int i = 0; i*k+k <= length; i++)
	{
		reverse(L.begin() + i*k, L.begin() + i*k + k);
	}
	length = L.size() - 1;
	for (int i = 0; i < length; i++)
	{
		printf("%05d %d %05d\n", L[i], LinkData[L[i]], L[i + 1]);
	}
	printf("%05d %d -1", L[length], LinkData[L[length]]);
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}