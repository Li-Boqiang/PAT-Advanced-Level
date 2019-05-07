#include<iostream>
#include<map>
#pragma warning(disable:4996)
using namespace std;

int N, ID;
map<int, int> paiming;
map<int, bool>jiancha;
bool isPrime(int x)
{
	for (int i = 2; i*i <= x; i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}
void solution()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> ID;
		paiming[ID] = i;
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> ID;
		if (!paiming.count(ID))
			printf("%04d: Are you kidding?\n", ID);
		else
		{
			if (!jiancha.count(ID))
			{
				if (paiming[ID] == 1)
					printf("%04d: Mystery Award\n", ID);
				else if (isPrime(paiming[ID]))
					printf("%04d: Minion\n", ID);
				else
					printf("%04d: Chocolate\n", ID);
				jiancha[ID] = true;
			}
			else
				printf("%04d: Checked\n", ID);
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