#include<iostream>
#include<string>
#pragma warning(disable:4996)
using namespace std;

string str;
long int res = 0;
int P = 0, A = 0, T = 0;			//计数这个字符串中有多少个PAT
void solution()
{
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'T') T++;
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'P') P++;
		if (str[i] == 'T') T--;
		if (str[i] == 'A')res += P*T;
	}
	cout << res % 1000000007;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}