//发现有以下特点，给定的数字中，让前面含有0最多的当第一个数，这样可以降低数量级
//字符串321是大于32的
//数字的最大位数是8位
//由于总是要把两个数进行连起来，所以在比较的时候就采用这种方法，字符串"ab"和字符串"ba"进行比较
//这道题思路巧妙，但是并未用到图的相关内容
#include<iostream>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;

int N;

string str[10001];

bool comp(string a, string b)
{
	string temp1 = a;
	string temp2 = b;
	temp1 += b;
	temp2 += a;
	return temp1 < temp2;
}

void solution()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> str[i];
	bool flag = false;
	sort(str, str + N, comp);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < str[i].length(); j++)
		{
			if (!flag&&str[i][j] == '0')
				;
			else
			{
				flag = 1;
				cout << str[i][j];
			}
		}
	}
	if (!flag)
		cout << '0';
	cout << endl;

}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}