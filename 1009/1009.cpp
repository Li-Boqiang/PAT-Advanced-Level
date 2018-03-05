//多项式乘法问题
//是按照指数依次下降的顺序给出的
#include<iostream>
#include<iomanip>
#pragma warning(disable:4996)


using namespace std;
int k1, k2;								//k1  k2是存储多项式的项数
int zhishu1[11], zhishu2[11];						//多项式1、2的指数和系数信息
float xishu1[11], xishu2[11];

void solution()
{
	float res[2002] = {0};
	int num = 0;
	freopen("1.txt", "r", stdin);
	cin >> k1;
	for (int i = 0; i < k1; i++)
		cin >> zhishu1[i] >> xishu1[i];
	cin >> k2;
	for (int i = 0; i < k2; i++)
		cin >> zhishu2[i] >> xishu2[i];
	//输入完所有的信息。下面开始计算

	for (int i = 0; i < k1; i++)
	{
		for (int j = 0; j < k2; j++)
		{
			res[zhishu1[i] + zhishu2[j]] += xishu1[i] * xishu2[j];							//多项式相乘，指数相加，系数相乘，最后系数求和
		}
	}

	for (int i = 0; i < 2002; i++)
	{
		if (res[i] != 0)
			num++;
	}
	cout << num;
	for (int i = 2001; i >= 0 ; i--)
	{
		if (res[i]!=0)
		{
			cout << ' ' << i ;
			cout << fixed << setprecision(1) << ' ' << res[i] ;
		}
	}
}

int main()
{
	solution();
	system("pause");
	return 0;
}