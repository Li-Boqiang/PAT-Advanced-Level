#include<iostream>
#include<map>
#include<string>
#pragma warning(disable:4996)
using namespace std;

map<string, int> gewei, shiwei;
string a[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct","nov", "dec" };
string b[13] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy","lok", "mer", "jou" };
void init()
{
	for (int i = 0; i < 13; i++)
		gewei[a[i]] = i;
	for (int i = 1; i < 13; i++)
		shiwei[b[i]] = i;
}

void f1(string str)			//输入的是数字
{
	int temp = stoi(str);

	if (temp / 13 > 0)
	{
		cout << b[temp / 13];
		if (temp % 13)
			cout << ' ' << a[temp % 13];
	}
	else
		cout << a[temp % 13];
}
void f2(string str)
{
	if (str.length() == 4)
		cout << "0";
	else if (str.length() == 3)
	{
		if (gewei.count(str))
			cout << gewei[str];
		if (shiwei.count(str))
			cout << shiwei[str]*13;
	}
	else
	{
		string s1 = str.substr(0, 3), s2 = str.substr(4, 3);
		int temp = shiwei[s1] * 13 + gewei[s2];
		cout << temp;
	}
}
void solution()
{
	init();
	int N,temp;
	cin >> N; getchar();
	string num;
	for (int i = 0; i < N; i++)
	{
		getline(cin, num);
		if (isdigit(num[0]))		//是个数字
			f1(num);
		else
			f2(num);
		cout << endl;
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}