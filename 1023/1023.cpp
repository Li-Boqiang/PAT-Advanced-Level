//unsigned long long的最大值：1844674407370955161
//所以这个题得用数组去做
//注意，跟原来一样，意思是，数字种类一样，个数也必须一样。
#include<iostream>
#include<string>
#pragma warning(disable:4996)

using namespace std;
string Number;
int Number_int[25];
int Number_double[25];
int check[10] = { 0 };
int Length;
bool Flag = true;

void solution()
{
	cin >> Number;
	for (int i = 0; i < Number.size(); i++)
	{
		Number_int[i] = Number[i] - '0';
		check[Number_int[i]] ++;
	}
	//初始化
	int temp=0;										//用于保存进位
	for (int i = Number.size(); i>0  ; i--)
	{
		Number_double[i] = (Number_int[i-1] * 2+temp) % 10;
		temp = (Number_int[i-1] * 2 + temp) / 10;		//下一个的进位
	}
	if (temp > 0)									//产生进位
	{
		Number_double[0] = temp;
		cout << "No" << endl;
		for (int i = 0; i <= Number.size(); i++)
			cout << Number_double[i];
		cout << endl;
	}
	else
	{
		for (int i = 1; i <= Number.size(); i++)
			if ((check[Number_double[i]]--) <= 0)
				Flag = false;
		if (Flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		for (int i = 1; i <= Number.size(); i++)
			cout << Number_double[i];
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