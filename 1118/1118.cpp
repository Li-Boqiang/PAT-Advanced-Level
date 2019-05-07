#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
int N,temp1,temp2;
int par[10001];
int num[10001] = { 0 };
int FindRoot(int x)
{
	int j, k = x;
	while (x != par[x])
		x = par[x];
	while (k != x)
	{
		j = par[k];
		par[k] = x;
		k = j;
	}
	return x;
}
void merge(int x, int y)
{
	x = FindRoot(x);
	y = FindRoot(y);
	if (x == y)
		return;
	else
	{
		par[y] = x;
		num[x] += num[y];
	}
}
void solution()
{
	cin >> N;
	for (int i = 0; i < 10001; i++)
	{
		par[i] = i;
	}
	int k;
	for (int i = 0; i < N; i++)
	{
		cin >> k;
		cin >> temp1;
		if (num[temp1] == 0)
			num[temp1]++;
		for (int i = 1; i < k; i++)
		{
			cin >> temp2;
			if (num[temp2] == 0)
				num[temp2]++;
			merge(temp1, temp2);
		}
	}
	int cnt = 0, bird = 0;
	for (int i = 1; i < 10001; i++)
	{
		if (num[i]!=0)
		{
			bird++;
			if (par[i] == i)
				cnt++;
		}
	}
	cout << cnt << ' ' << bird << endl;
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		cin >> temp1 >> temp2;
		if (FindRoot(temp1) == FindRoot(temp2))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}