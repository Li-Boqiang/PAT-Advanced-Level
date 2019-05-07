#include<iostream>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

string num1, num2, num3;
string getsum(string a, string b)
{
	string c; int jinwei = 0, res = 0;
	for (int i = a.size()-1; i >= 0; i--)
	{
		res = a[i] + b[i] - '0' - '0' + jinwei;
		jinwei = 0;
		if (res > 9)
		{
			res = res - 10;
			jinwei = 1;
		}
		c += res + '0';
		res = 0;
	}
	if (jinwei)
		c += jinwei + '0';
	reverse(c.begin(), c.end());
	return c;
}
void solution()
{
	cin >> num1;
	num2 = num1;
	reverse(num1.begin(),num1.end());
	int cnt = 10;
	while (num1 != num2&&cnt--)
	{
		cout << num2 << " + " << num1 << " = ";
		num1 = getsum(num1, num2);
		cout << num1 << endl;
		num2 = num1;
		reverse(num1.begin(), num1.end());;
	} 
	if (num2 == num1)
		cout << num2 << " is a palindromic number.";
	else
		cout << "Not found in 10 iterations.";
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}