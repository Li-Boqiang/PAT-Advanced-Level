#include<iostream>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;
string str;
int length = 1;
void solution()
{
	for (int i = 0; i < str.size(); i++)
	{
		int n = 0, temp_length = 1;
		while (i-n>=0&&i+n<str.size()&&str[i-n]==str[i+n])
		{
			temp_length = 2 * n + 1;
			n++;
		}
		if (temp_length > length)
			length = temp_length;
		n = 0;
		while (i+1<str.size()&&str[i]==str[i+1]&&i-n>=0&&i+n+1<str.size()&&str[i-n]==str[i+n+1])
		{
			temp_length = 2 * n + 2;
			n++;
		}
		if (temp_length > length)
			length = temp_length;
	}
	cout << length;
}

int main()
{
	freopen("1.txt", "r", stdin);
	getline(cin, str);
	solution();
	system("pause");
	return 0;
}
