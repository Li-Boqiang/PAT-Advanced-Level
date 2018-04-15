#include<iostream>
#include<string>
#include<algorithm>
//#pragma warning(disable:4996)
using namespace std;
string str;
int length = 1;					//对称的长度最少为1
void solution()
{
	//以i为中心，j为长度
	for (int i = 0; i < str.size(); i++)
	{
		for (int j = 0; j <= min(i,int(str.size()-1-i)); j++)
		{
			string str2 = str.substr(i - j, 2 * j + 1);			//子字符串长度为奇数时
			string str3 = str2;
			reverse(str2.begin(), str2.end());
			if (str2 == str3)
				if (str2.size() > length)
					length = str2.size();
			str2 = str.substr(i - j, 2 * j + 2);			//子字符串长度为偶数时
			str3 = str2;
			reverse(str2.begin(), str2.end());
			if (str2 == str3)
				if (str2.size() > length)
					length = str2.size();
		}

	}
	cout << length;
}

int main()
{
	//freopen("1.txt", "r", stdin);
	getline(cin, str);
	solution();
	//system("pause");
	return 0;
}