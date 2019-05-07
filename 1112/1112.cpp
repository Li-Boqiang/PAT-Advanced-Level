#include<iostream>
#include<string>
#include<map>
#pragma warning(disable:4996)
using namespace std;

int N;
string str;
map<char, bool>res, temp;
bool flag = false;
void solution()
{
	cin >> N >> str;
	int i = 0;
	for (i = 0; i <= str.size()-N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (str[i + j] == str[i])
			{
				if (!res.count(str[i]))
					res[str[i]] = true;
			}
			else
			{
				res[str[i]] = false;
				break;
			}
		}
		if (res[str[i]] == true)
			i += (N - 1);
	}
	for (; i < str.size(); i++)
		res[str[i]] = false;
	for (int i = 0; i < str.size(); i++)
		if (res[str[i]] == true&&!temp.count(str[i]))
		{
			cout << str[i];
			temp[str[i]] = true;
		}
	cout << endl;
	for (int i = 0; i < str.size(); i++)
	{
		if (res[str[i]] == false)
			cout << str[i];
		else
		{
			cout << str[i];
			i += (N - 1);
		}
	}
}

int main()
{
	freopen("3.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}