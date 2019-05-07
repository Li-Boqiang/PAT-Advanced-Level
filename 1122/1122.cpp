#include<iostream>

#pragma warning(disable:4996)
using namespace std;

int N, M, e1, e2, n;
bool m[201][201] = { 0 };
bool visit[201] = { 0 };

void solution()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> e1 >> e2;
		m[e1][e2] = true;
		m[e2][e1] = true;
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		bool flag = true;
		fill(visit, visit+201, 0);
		cin >> n;
		cin >> e1;
		int f = e1;
		visit[e1] = true;
		for (int i = 1; i < n; i++)
		{
			cin >> e2;
			if (m[e1][e2] == true)
			{
				if (visit[e2] == false)
					visit[e2] = true;
				else if(i != n - 1)
					flag = false;
			}
			else
				flag = false;
			e1 = e2;
		}
		if (f != e2)
			flag = false;
		for (int i = 1; i <= N; i++)
		{
			if (visit[i] == false)
				flag = false;
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}