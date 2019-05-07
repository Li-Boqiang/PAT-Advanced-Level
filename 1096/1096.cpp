#include<iostream>
#include<cmath>
#pragma warning(disable:4996)
using namespace std;

long int num;
void solution()
{
	cin >> num;
	long int temp = 1;
	int first = 0, len = 0, maxn = sqrt(num);
	for (int i = 2; i <= maxn; i++)
	{
		int j, temp = 1;
		for (j= i;j<=maxn;  j++)
		{
			temp *= j;
			if (num%temp != 0)break;
		}
		if (j - i > len)
		{
			len = j - i;
			first = i;
		}
	}
	if (first==0)cout << 1 << endl << num;			//ц╩спур╣╫
	else
	{
		cout << len << endl;
		for (int i = 0; i < len; i++)
		{
			cout << first + i;
			if (i != len - 1)cout << '*';
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