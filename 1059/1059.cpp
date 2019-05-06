#include<iostream>
#include<map>
#pragma warning(disable:4996)
using namespace std;

long int num;
map<long int, int>res;
void Prime_factor(long int n)
{
	for (int i = 2; i*i <= n; i++)
	{
		while (n%i == 0)
		{
			++res[i];
			n /= i;
		}
	}
	if (n != 1)res[n] = 1;
	return;
}
void solution()
{
	if (num == 1)
	{
		cout << "1=1";
		return;
	}
	Prime_factor(num);
	cout << num << '=';
	auto i = res.begin();
	if (i->second >= 2)
		cout << i->first << '^' << i->second;
	else
		cout << i->first;
	i++;
	for (; i != res.end(); i++)
	{
		if (i->second >= 2)
		{
			cout <<'*'<< i->first << '^' << i->second;
		}
		else
			cout << '*' << i->first;
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	cin >> num;
	solution();
	system("pause");
	return 0;
}