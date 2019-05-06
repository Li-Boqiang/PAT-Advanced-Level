#include<iostream>
#pragma warning(disable:4996)
using namespace std;

typedef struct 
{
	long long int member;	//分子部分
	long long int deno;		//分母部分
	long long int inte;		//整数部分
}fraction;
fraction num;
fraction res = {0,1,0};
long long int gcd(long long int a, long long int b)					//最大公约数,abs求绝对值
{
	return b == 0 ? abs(a) : gcd(b, a%b);
}

int N;
void solution()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%lld/%lld", &num.member,&num.deno);
		long long int gcd_num = gcd(num.member,num.deno);
		num.deno /= gcd_num; num.member /= gcd_num;
		res.member = res.member*num.deno + res.deno*num.member;
		res.deno = res.deno*num.deno;
		gcd_num = gcd(res.deno, res.member);
		res.deno /= gcd_num; res.member /= gcd_num;
	}
	res.inte = res.member / res.deno;
	res.member -= (res.deno*res.inte);
	if (res.inte!=0)
	{
		cout << res.inte;
		if (res.member!=0)
		{
			cout << ' ';
		}
	}
	if (res.member!=0)
	{
		cout << res.member << '/' << res.deno;
	}
	else if (res.inte==0)
	{
		cout << '0';
	}

}

int main()
{
	freopen("3.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}