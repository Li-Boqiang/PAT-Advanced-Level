#include<iostream>  
#pragma warning(disable:4996)

using namespace std;

int n, need, cost = 0, now = 0;					//floor是当前的层次，一开始定为0

void solution()
{
	freopen("2.txt", "r", stdin);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> need;
		if (need>now)
		{
			cost += (need - now) * 6 + 5;
		}
		else 
		{
			cost += (now - need) * 4 + 5;
		}
		now = need;
	}
	cout << cost;
}

int main()
{
	solution();
	system("pause");
	return 0;
}