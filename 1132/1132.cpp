#include<iostream>
#include<string>
#pragma warning(disable:4996)
using namespace std;

int N, num1, num2, num3;
string str1, str2, str3;
void solution()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str1;
		num1 = stoi(str1);
		str2 = str1.substr(0, str1.size() / 2);
		num2 = stoi(str2);
		str3 = str1.substr(str1.size() / 2);
		num3 = stoi(str3);
		if (num2*num3 != 0 && num1 % (num2*num3) == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}