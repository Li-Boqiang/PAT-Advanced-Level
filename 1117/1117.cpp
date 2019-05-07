#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

vector<int>v;
int N;
bool cmp(int a, int b)
{
	return a > b;
}
void solution()
{
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(),cmp);
	int i;
	for (i = 0; i < N&&v[i]>(i + 1); i++);
	cout << i;
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}