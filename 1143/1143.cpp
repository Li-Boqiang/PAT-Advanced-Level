#include<iostream>
#include<vector>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

int M, N;
unordered_set<int>s;
void solution()
{
	cin >> M >> N;
	vector<int>v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		s.insert(v[i]);
	}
	int v1, v2;
	while (M--)
	{
		cin >> v1 >> v2;
		bool flag1 = true, flag2 = true;
		if (s.find(v1) == s.end())
			flag1 = false;
		if (s.find(v2) == s.end())
			flag2 = false;
		if (!flag1 && !flag2)
		{
			printf("ERROR: %d and %d are not found.\n", v1, v2);
			continue;
		}
		else if (!flag1)
			printf("ERROR: %d is not found.\n", v1);
		else if (!flag2)
			printf("ERROR: %d is not found.\n", v2);
		else
			for (int i = 0; i < N; i++)
			{
				if ((v[i] >= v1&&v[i] <= v2) || (v[i] <= v1&&v[i] >= v2))
				{
					if (v[i] == v1)
						printf("%d is an ancestor of %d.\n", v1, v2);
					else if (v[i] == v2)
						printf("%d is an ancestor of %d.\n", v2, v1);
					else
						printf("LCA of %d and %d is %d.\n", v1, v2, v[i]);
					break;
				}
			}
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}	