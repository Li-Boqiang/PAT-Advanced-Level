#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

vector<int>G[1001];
int N, M, v1, v2;
vector<int> in;
void solution()
{
	cin >> N >> M;
	in.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		cin >> v1 >> v2;
		in[v2]++;
		G[v1].push_back(v2);
	}
	int K;
	cin >> K;
	vector<int>res;
	for (int i = 0; i < K; i++)
	{
		vector<int>temp = in;
		bool flag = true;
		int node;
		for (int i = 0; i < N; i++)
		{
			cin >> node;
			if (temp[node] != 0)
				flag = false;
			if(flag==true)
				for (int j = 0; j < G[node].size(); j++)
					temp[G[node][j]]--;
		}
		if (flag == false)
			res.push_back(i);
	}
	for (int i = 0; i < res.size(); i++)
	{
		if (i != 0)
			cout << ' ';
		cout << res[i];
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}