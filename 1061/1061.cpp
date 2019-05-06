#include<iostream>
#include<string>
#pragma warning(disable:4996)
using namespace std;

string Week[7] = { "MON ","TUE ","WED ","THU ","FRI ","SAT ","SUN " };
string str1, str2, str3, str4;
void solution()
{
	bool flag = false;
	for (int i = 0; i<str1.size() && i<str2.size(); i++)
	{

		if (str1[i] == str2[i] && flag == false && str1[i] <= 'G'&&str1[i] >= 'A')				//ע�ⷶΧA~G
		{
			cout << Week[str1[i] - 'A'];
			flag = true;
			i++;
		}
		if (str1[i] == str2[i] && flag == true && ((str1[i] <= 'N'&&str1[i] >= 'A') || (str1[i] <= '9'&&str1[i] >= '0')))	//ע�ⷶΧA~N
		{
			if (str1[i] <= '9'&&str1[i] >= '0')
				printf("%02d:", str1[i] - '0');
			else
				cout << 10 + str1[i] - 'A' << ':';
			break;
		}
	}
	for (int i = 0; i < str3.size() && i<str4.size(); i++)
	{
		if (str3[i] == str4[i] && ((str3[i] <= 'Z'&&str3[i] >= 'A') || (str3[i] <= 'z'&&str3[i] >= 'a')))
		{
			printf("%02d", i);
			return;
		}
	}
}

int main()
{
	freopen("2.txt", "r", stdin);
	cin >> str1 >> str2 >> str3 >> str4;
	solution();
	system("pause");
	return 0;
}