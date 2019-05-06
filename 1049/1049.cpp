#include<iostream>
#pragma warning(disable:4996)
using namespace std;
int num;
void solution()
{
	cin >> num;
	int left = 0, right = 0,now=0, res = 0;
	for (int i = 1; num/i!=0; i=i*10)
	{
		left = num / (i * 10);
		now = num / i % 10;
		right = num%i;
		if (now == 0)
		{
			res += left*i;
		}
		else if (now == 1)
			res += left*i + right + 1;
		else
			res += (left + 1)*i;
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