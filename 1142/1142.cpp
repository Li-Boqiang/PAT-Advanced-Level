#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
bool G[201][201] = { 0 };
int Ne, Nv, M, K,v1,v2;
void solution()
{
	cin >> Nv >> Ne;
	for (int i = 0; i < Ne; i++)
	{
		cin >> v1 >> v2;
		G[v1][v2] = 1;
		G[v2][v1] = 1;
	}
	cin >> M;
	while (M--)
	{
		cin >> K;
		vector<int> v(K);
		vector<bool> temp(Nv + 1);
		bool isClique = true, isMax = true;
		for (int i = 0; i < K; i++)
		{
			cin >> v[i];
			temp[v[i]] = true;
		}
		for (int i = 0; i < K&&isClique; i++)
		{
			for (int j = i+1; j < K; j++)							//验证是否两两相连
			{
				if (G[v[i]][v[j]]==0)
				{
					isClique = false;
					cout << "Not a Clique" << endl;
					break;
				}
			}
		}
		if (!isClique)
			continue;
		for (int i = 1; i <= Nv&&isMax ; i++)
		{
			if(temp[i]==0)
				for (int j = 0; j < K; j++)
				{
					if (G[v[j]][i] == 0)			//有一个不相连的直接跳出循环
						break;
					if (j == K - 1)
					{
						cout << "Not Maximal" << endl;
						isMax = 0;
					}
				}
		}
		if(isMax)
			cout << "Yes" << endl;
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}