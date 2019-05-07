#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

int N;
vector<int> temp1, num, res;


void solution()
{
	cin >> N; num.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);
	temp1 = num;
	sort(temp1.begin(), temp1.end());
	int maxn = 0;
	for (int i = 0; i < N; i++)
	{
		if (num[i] == temp1[i] && num[i] > maxn)
			res.push_back(num[i]);
		maxn = max(maxn, num[i]);
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
		if (i != res.size() - 1)
			cout << ' ';
	}
	cout << endl;
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}