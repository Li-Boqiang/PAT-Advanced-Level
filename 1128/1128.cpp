#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
int N, K;
void solution()
{
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> N;
		vector<int> v(N);
		bool res = true;
		for (int j = 0; j < N; j++)					//j表示列，v[j]表示行
		{
			scanf("%d", &v[j]);
			if (res==true)
			{
				for (int t = 0; t < j; t++)
				{
					if (v[j] == v[t] || abs(v[j] - v[t]) == abs(j - t))
					{
						res = false;
						break;
					}
				}
			}
		}
		if (res)
			printf("YES\n");
		else
			printf("NO\n");
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}