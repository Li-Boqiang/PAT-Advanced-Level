#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
vector<int> par;
int hobby[1001] = { 0 }, N;
int num[1001];				//表示以i为根的圈子的大小
bool cmp(int a, int b)
{
	return a > b;
}
bool cmp2(int a, int b)
{
	return num[a] > num[b];
}

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
	par.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		par[i] = i;
		num[i] = 1;
	}
	int k, h;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d: ", &k);
		for (int j = 0; j < k; j++)
		{
			cin >> h;
			if (hobby[h] == 0)
				hobby[h] = i;
			else
			{
				merge(i, hobby[h]);
			}
		}
	}
	int cnt = 0; vector<int>res;
	for (int i = 1; i <= N; i++)
	{
		if (par[i] == i)
		{
			cnt++;
			res.push_back(i);
		}
	}
	sort(res.begin(), res.end(), cmp2);
	cout << cnt << endl;
	for (int i = 0; i < res.size(); i++)
	{
		cout << num[res[i]];
		if (i != res.size() - 1)
			cout << ' ';
	}
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}