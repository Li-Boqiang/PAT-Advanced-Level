#include<iostream>
#include<string>
#pragma warning(disable:4996)
using namespace std;

string str;
int num;
void solution()
{
	cin >> str;
	int pos_e, pos_exp;
	bool isPositive = true;
	if (str[0] == '-')
		isPositive = false;
	pos_e = str.find('E');
	string str_num = str.substr(1, pos_e - 1);
	string str_exp = str.substr(pos_e + 1);
	//double num = stod(str_num);
	int exp = stoi(str_exp);
	if (exp > 0)
	{
		str_num.erase(1, 1);			//去掉小数点
		if (exp < str_num.size() - 1)
			str_num.insert(exp + 1, ".");	//重新确定小数点
		else
		{
			int pos = exp - (str_num.size() - 1);
			for (int i = 0; i < pos; i++)
			{
				str_num += '0';			//在后面添加0
			}
		}
	}
	else if (exp<0)
	{
		str_num.erase(1, 1);			//去掉小数点
		for (int i = 0; i < (-exp); i++)
		{
			str_num.insert(0, "0");
		}
		str_num.insert(1, ".");			//填完0之后再加上小数点
	}
	if (!isPositive)
		cout << '-';
	cout << str_num;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}