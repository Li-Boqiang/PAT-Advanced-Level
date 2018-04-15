#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)

using namespace std;
int N, M;
vector<int> coins;
void solution()
{
	sort(coins.begin(), coins.end());
	int j = N - 1;
	for (int i = 0; i<j; )
	{
		if (coins[i] + coins[j] == M)
		{
			cout << coins[i] << ' ' << coins[j];
			return;
		}
		else if (coins[i] + coins[j] > M)
			j--;
		else
			i++;
	}
	cout << "No Solution";
}

int main()
{
	freopen("1.txt", "r", stdin);
	cin >> N >> M;
	coins.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> coins[i];
	}
	solution();
	system("pause");
	return 0;
}