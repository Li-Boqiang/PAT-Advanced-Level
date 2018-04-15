#include<iostream>
#pragma warning(disable:4996)
using namespace std;
int input[100001];
int countNumber[100001] = {0};
int N;
void solution()
{
	for (int i = 0; i < N; i++)
	{
		countNumber[input[i]]++;
	}
	for (int i = 0; i < N; i++)
	{
		if (countNumber[input[i]] == 1)
		{
			cout << input[i];
			return;
		}
	}
	cout << "None";
	return;
}

int main()
{
	freopen("2.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
	}
	solution();
	system("pause");
	return 0;
}