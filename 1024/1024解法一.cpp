//判断回文数的方法，逆置，看逆置前后是否相等
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string num;

void getsum(string str)
{
	
	int length = str.length();
	int carry = 0;
	for (int i = 0; i < length; i++)
	{
		num[i] = num[i] + str[i] + carry - '0';
		carry = 0;
		if (num[i]>'9')
		{
			num[i] = num[i] - 10;
			carry = 1;
		}
	}
	if (carry)
	{
		num += '1';
	}
	reverse(num.begin(), num.end());
}
void solution()
{
	int count, n;
	string str;
	cin >> num >> count;
	for (int i = 0; i < n; i++)
	{
		str = num;
		reverse(str.begin(), str.end());//str是num的逆置
		if (str==num)
		{
			cout << num << endl << i;
			return;
		}
		getsum(str);
	}
	cout << num << endl << n;
}
int main()
{
	solution();
	return 0;
}


