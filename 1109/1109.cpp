#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
typedef struct 
{
	string name;
	int len;
}node;
bool cmp(node a, node b)
{
	if (a.len != b.len)
		return a.len > b.len;
	else
		return a.name < b.name;
}
vector<node> v;
vector<string> res;
int N, K, row, cnt = 0;
void solution()
{
	cin >> N >> K;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i].name >> v[i].len;
	sort(v.begin(), v.end(), cmp);
	row = K;
	int num;
	while (row>0)
	{
		bool flag = false;
		if (row == K)
			num = N - N / K*(K - 1);
		else
			num = N / K;
		res.resize(num);
		res[num / 2] = v[cnt++].name;
		for (int i = 1; i < num; i++)
		{
			if (flag==false)
			{
				res[num / 2 - (i + 1) / 2] = v[cnt++].name;
				flag = true;
			}
			else
			{
				res[num / 2 + (i + 1) / 2] = v[cnt++].name;
				flag = false;
			}
		}
		row--;
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i];
			if (i!=res.size()-1)
			{
				cout << ' ';
			}
		}
		cout << endl;
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}