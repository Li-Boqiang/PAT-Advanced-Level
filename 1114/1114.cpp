#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
int N, K;
typedef struct 
{
	int ID, fID, mID, fangzi, mianji;
	int child[6];
}node;
int par[10001];
typedef struct 
{
	int shuliang = 0;
	int area = 0;
	int renshu = 0;
}fangzi;
//int num[10001];
node info[1001];
fangzi num[10001];
bool visit[10001] = { 0 };
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
vector<int> res;
void merge(int x, int y)
{
	x = FindRoot(x);

	y = FindRoot(y);
	if (x == y)
		return;
	if (x > y)
	{
		par[x] = y;
		num[y].shuliang += num[x].shuliang;
		num[y].area += num[x].area;
	}
	else
	{
		par[y] = x;
		num[x].shuliang += num[y].shuliang;
		num[x].area += num[y].area;
	}
}

bool cmp(int a, int b)
{
	double x = 1.0*num[a].area / num[a].renshu;
	double y = 1.0*num[b].area / num[b].renshu;
	if (x != y)
		return x > y;
	else
		return a < b;
}
void solution()
{
	cin >> N;
	for (int i = 0; i < 10001; i++)
	{
		par[i] = i;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> info[i].ID >> info[i].fID >> info[i].mID;
		visit[info[i].ID] = true;
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> info[i].child[j];
			visit[info[i].child[j]] = true;
		}
		int a, b;
		cin >> a >> b;
		num[FindRoot(info[i].ID)].shuliang += a;
		num[FindRoot(info[i].ID)].area += b;
		if (info[i].fID != -1)
		{
			merge(info[i].ID, info[i].fID);
			visit[info[i].fID] = true;
		} 
		if (info[i].mID != -1)
		{
			merge(info[i].ID, info[i].mID);
			visit[info[i].mID] = true;
		}
		for (int j = 0; j < k; j++)
		{
			merge(info[i].ID, info[i].child[j]);
		}
	}
	for (int i = 0; i < 10001; i++)
	{
		if (visit[i]==true)
		{
			num[FindRoot(i)].renshu++;
			if (par[i] == i)
				res.push_back(i);
		}
	}
	sort(res.begin(), res.end(), cmp);
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++)
	{
		printf("%04d %d %.3f %.3f\n", res[i], num[res[i]].renshu, 1.0*num[res[i]].shuliang / num[res[i]].renshu, 1.0*num[res[i]].area / num[res[i]].renshu);
	}
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}