#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int temp, N;
bool num[100001] = { 0 };
void solution()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		if (temp > N || temp <= 0)
			continue;
		num[temp] = true;
	}
	int i;
	for (i = 1; i <= N; i++)
	{
		if (num[i] == false)
		{
			cout << i;
			return;
		}
	}
	cout << i;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}