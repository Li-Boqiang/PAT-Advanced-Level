#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int N;
double num[100001], sum = 0.0;
void solution()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
		sum += num[i] * i * (N - i + 1);
	}
	printf("%.2f", sum);
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}