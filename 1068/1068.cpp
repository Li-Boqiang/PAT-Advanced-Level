/*
题目大意：给出10^4个硬币，让你找出一个序列，使其和等于给定值M.
要求这个序列中的每个数字尽可能的小，每个数字最多仅能被使用一次
这个是个动态规划的背包问题
*/
#include<iostream>
#include<algorithm>

#pragma warning(disable:4996)

using namespace std;
int N, M;							//N是硬币的数量，M是需要支付的总额
int Coin[10001];
int Result[10001];

bool comp(int a, int b)
{
	return a < b;
}

void solution()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> Coin[i];				//input all data
	sort(Coin, &Coin[N - 1],comp);	//rank form low to high
	bool Find_coin = false;
	int Total = 0;
	for (int i = 0; i < N; i++)
	{
		Total += Coin[i];
		if (Total)
		{

		}
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}