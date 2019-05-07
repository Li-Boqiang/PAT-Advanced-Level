#include<iostream>
#pragma warning(disable:4996)
using namespace std;
typedef struct
{
	long long int member;	//分子部分
	long long int deno;		//分母部分
	long long int inte;		//整数部分
}fraction;
fraction num[2];
fraction res[4];
long long int gcd(long long int a, long long int b)					//最大公约数,abs求绝对值
{
	return b == 0 ? abs(a) : gcd(b, a%b);
}

void shuchu(fraction a)
{
	if (a.inte < 0 || a.member < 0)
		cout << '(';
	if (a.inte!=0)
	{
		cout << a.inte;
		if (a.member!=0)
		{
			cout << ' ';
		}
	}
	if (a.member != 0)
	{
		cout << a.member << '/' << a.deno;
	}
	else if (a.inte == 0)
		cout << '0';
	if (a.inte < 0 || a.member < 0)
		cout << ')';
}

void jiafenshu(fraction &a)
{
	long long int gcd_num = gcd(a.member, a.deno);
	a.deno /= gcd_num; a.member /= gcd_num;
}

void daifenshu(fraction &a)
{
	a.inte = a.member / a.deno;
	a.member -= (a.deno*a.inte);
	if (a.inte < 0)
		a.member = abs(a.member);
}
void solution()
{
	for (int i = 0; i < 2; i++)
	{
		scanf("%lld/%lld", &num[i].member, &num[i].deno);
		jiafenshu(num[i]);
	}
	
	//+
	res[0].member = num[1].member*num[0].deno + num[1].deno*num[0].member;
	res[0].deno = num[1].deno*num[0].deno;

	//-
	res[1].member = num[1].deno*num[0].member - num[1].member*num[0].deno;
	res[1].deno = num[1].deno*num[0].deno;

	//*
	res[2].member = num[1].member*num[0].member;
	res[2].deno = num[1].deno*num[0].deno;

	// /
	bool flag = false;
	if (num[1].member == 0 && num[1].inte == 0)
		flag = true;
	if (!flag)
	{
		res[3].member = num[0].member*num[1].deno;
		res[3].deno = num[0].deno*num[1].member;
		if (res[3].deno*res[3].member < 0)
		{
			res[3].member = 0 - abs(res[3].member);
			res[3].deno = abs(res[3].deno);
		}
	}
	else
		res[3] = { 0,1,0 };

	for (int i = 0; i < 2; i++)
	{
		daifenshu(num[i]);
	}
	for (int i = 0; i < 4; i++)
	{//化简
		jiafenshu(res[i]);
		daifenshu(res[i]);
	}
	//输出
	shuchu(num[0]); cout << " + "; shuchu(num[1]); cout << " = "; shuchu(res[0]); cout << endl;
	shuchu(num[0]); cout << " - "; shuchu(num[1]); cout << " = "; shuchu(res[1]); cout << endl;
	shuchu(num[0]); cout << " * "; shuchu(num[1]); cout << " = "; shuchu(res[2]); cout << endl;
	shuchu(num[0]); cout << " / "; shuchu(num[1]); cout << " = ";
	if (flag)
		cout << "Inf";
	else
		shuchu(res[3]);
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}