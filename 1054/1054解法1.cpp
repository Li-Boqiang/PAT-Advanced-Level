#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)

using namespace std;
int N, M;
vector<int> color;
void solution()
{
	cin >> M >> N;
	int input;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &input);
			color.push_back(input);
		}
	}
	sort(color.begin(), color.end());
	cout << color[color.size() / 2];
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}