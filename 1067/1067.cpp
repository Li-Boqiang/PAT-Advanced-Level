#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int num[100001];
bool visit[100001] = { 0 };
int N, group = 0, swap_time = 0;
void solution()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	for (int i = 0; i < N; i++)
	{
		if (visit[i] || num[i] == i)
			continue;
		group++;
		int j = i;
		while (!visit[j])
		{
			visit[j] = true;
			swap_time++;
			j = num[j];
		}
	}
	if (num[0] != 0)
		cout << swap_time + group - 2;
	else
		cout << swap_time + group;
	return;
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}