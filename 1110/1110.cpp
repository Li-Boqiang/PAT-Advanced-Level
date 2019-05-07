#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
typedef	struct 
{
	int ID;
	int lchild, rchild;
}node;
queue<int>que;
int N;
vector<node> v, s;
string temp;
bool FindRoot[21] = { 0 };
bool cmp(node a, node b)
{
	return a.ID < b.ID;
}
void solution()
{
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
	{	
		cin >> temp;
		if (temp[0] != '-')
		{
			v[i].lchild = stoi(temp);
			FindRoot[v[i].lchild] = true;
		}
		else
			v[i].lchild = -1;
		cin >> temp;
		if (temp[0] != '-')
		{
			v[i].rchild = stoi(temp);
			FindRoot[v[i].rchild] = true;
		}
		else
			v[i].rchild = -1;
	}
	int root;
	for (int i = 0; i < N; i++)
	{
		if (FindRoot[i] == false)
		{
			root = i;
			break;
		}
	}
	que.push(root);
	int f, cnt = 1;
	while (!que.empty())
	{
		f = que.front(); que.pop(); v[f].ID = cnt++;
		if (v[f].lchild != -1)
			que.push(v[f].lchild);
		if (v[f].rchild != -1)
			que.push(v[f].rchild);
	}
	s = v;
	sort(s.begin(), s.end(), cmp);
	bool flag=true;
	for (int i = 0; i < N; i++)
	{
		if (s[i].lchild != -1 && v[s[i].lchild].ID != s[i].ID * 2)
			flag = false;
		if (s[i].rchild != -1 && v[s[i].rchild].ID != s[i].ID * 2 + 1)
			flag = false;
	}
	if (flag)
		cout << "YES " << f;
	else
		cout << "NO " << root;
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}