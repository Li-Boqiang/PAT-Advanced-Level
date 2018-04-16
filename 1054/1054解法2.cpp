#include<iostream>
#include<map>
#pragma warning(disable:4996)
using namespace std;
map<int, int> color;
int M, N;
void solution()
{
	cin >> M >> N;
	int input,half=M*N/2;
	for (int i = 0; i <N; i++)
	{
		for (int i = 0; i < M; i++)
		{
			scanf("%d", &input);
			color[input]++;
			if (color[input]>half)
			{
				printf("%d", input);
				return;
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
