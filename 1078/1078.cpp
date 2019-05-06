#include<iostream>
#pragma warning(disable:4996)
using namespace std;

bool isPrime(int num)			//ÅĞ¶ÏËØÊı
{
	if (num == 1)
		return false;
	for (int i = 2; i *i<= num; i++)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}

bool hashTable[10010] = {0};
void solution()
{
	int tsize, n;
	cin >> tsize >> n;
	while (!isPrime(tsize))
	{
		tsize++;
	}
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		int j,k;
		for (j = 0; j < tsize; j++)
		{
			k = (temp + j*j) % tsize;		//Æ½·½Ì½²â
			if (!hashTable[k])
			{
				hashTable[k] = true;
				cout << k;
				break;
			}
		}
		if (j == tsize)
			cout << "-";
		if (i != n - 1)
			cout << ' ';
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
