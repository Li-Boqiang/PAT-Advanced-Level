#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

vector<long int>v;
int N,M;
void solution()
{
	sort(v.begin(), v.end());
	int i = (v.size() - 1)/2;
	cout << v[i];
}

int main()
{
	freopen("1.txt", "r", stdin);
	cin >> N;
	v.resize(N);
	long int temp;
	for (int i = 0; i < N; i++)
	{
		scanf("%ld", &temp);
		v[i] = temp;
	}
	cin >> M;
	v.resize(N + M);
	for (int i = N; i < M+N; i++)
	{
		scanf("%ld",&temp);
		v[i] = temp;
	}
	
	solution();
	system("pause");
	return 0;
}
