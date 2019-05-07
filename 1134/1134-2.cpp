#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

int N, M, K, Nv, v1, v2;
vector<vector<int>>G;
void solution()
{
	scanf("%d %d", &N, &M);
	G.resize(N);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &v1, &v2);
		G[v1].push_back(i);				//给第i条边命名为边i
		G[v2].push_back(i);
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		scanf("%d",&Nv);
		bool flag = true;
		vector<bool>hash(M);
		for (int j = 0; j < Nv; j++)
		{
			scanf("%d", &v1);
			for (int t = 0; t < G[v1].size(); t++)
				hash[G[v1][t]] = true;
		}
		for (int j = 0; j < M; j++)
		{
			if (hash[j]==false)
			{
				printf("No\n");
				flag = false;
				break;
			}
		}
		if (flag == true)
			printf("Yes\n");
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}