#include<iostream>
#include<string>
#pragma warning(disable:4996)
using namespace std;

string str;
int N;
void solution()
{
	cin >> str >> N;
	for (int i = 1; i < N; i++)
	{
		string temp;
		int j;
		for (int i = 0; i < str.length(); i=j)
		{
			for (j = i; j < str.length() && str[j] == str[i]; j++);
			temp += str[i] ;
			temp += (j - i) + '0';
		}
		str = temp;
	}
	cout << str;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}