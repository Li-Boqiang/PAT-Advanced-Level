#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
int N, sum1 = 0, sum2 = 0;
vector<int> v;
void solution()
{
	cin >> N; v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0; i < N/2; i++)
		sum1 += v[i];
	for (int i = N/2; i < N; i++)
		sum2 += v[i];
	cout << N % 2 << ' ' <<  sum2 - sum1;
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}