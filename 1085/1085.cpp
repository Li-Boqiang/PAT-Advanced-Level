#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#pragma warning(disable:4996)
using namespace std;

vector<int> list;
long int N, p;
int res = 0;			//num表示有多少个数

void solution()
{
	cin >> N >> p;
	list.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
	}
	sort(list.begin(), list.end());
	long long int temp;
	for (auto i = list.begin(); i !=list.end(); i++)
	{
		temp = *i * p;
		res=max((int)(upper_bound(list.begin(), list.end(), temp)-i),res);
	}
	
	cout << res;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}