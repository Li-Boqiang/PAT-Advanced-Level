#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

int node[100001] = {0};
bool visit[100001] = {0};
int startPoint1, startPoint2, N;

void solution()
{
	for (int i = startPoint1; i != -1; i=node[i])
		visit[i] = true;
	for (int i = startPoint2; i != -1; i=node[i])
	{
		if (visit[i])
		{
			printf("%05d", i);
			return;
		}

		visit[i] = true;
	}
	cout << "-1";
}

int main()
{
	freopen("2.txt", "r", stdin);
	char ch;
	int addr, next;
	cin >> startPoint1 >> startPoint2 >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> addr >> ch >> next;
		node[addr] = next;
	}
	solution();
	system("pause");
	return 0;
}