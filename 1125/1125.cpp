#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int N;
vector<int>v;
void solution()
{
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());
	double len = v[0];
	for (int i = 1; i < N; i++)
		len = len / 2 + v[i] * 1.0 / 2;
	printf("%d", (int)len);
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}