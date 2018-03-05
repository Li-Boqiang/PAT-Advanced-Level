//判断的条件：
//1.本身就是一个素数
//2.他的D进制的反序数，转为10进制之后，也是个素数
#include<iostream>
#include<string>
#include<cmath>
#pragma warning(disable:4996)
using namespace std;

int N, D;

int TrasToTen(string n, int rad)					//将字符串转为十进制
{
	int num;								//表示位数
	int res = 0;
	for (int i = 0; i < n.length(); i++)
		res = res*rad + (n[i] - '0');
	return res;
}
bool Check(int n)							//用于检查是不是素数
{
	int a = sqrt(n);
	int flag;
	if (n == 1)
		return false;
	for (int i = a; i > 1; i--)
	{
		flag = n%i;							//求余数
		if (!flag)							//如果为0
			return false;					//不是素数
	}
	return true;
}

void solution()
{
	while (true)
	{
		string str;
		cin >> N;
		if (N < 0)
			return;
		cin >> D;
		bool flag = Check(N);
		if (!flag)
		{
			cout << "No" << endl;
			continue;
		}
		int c;
		while (N!=0)
		{
			c = N%D;
			N /= D;
			str = str + to_string(c);
		}
		//reverse(str.begin(), str.end());
		flag = Check(TrasToTen(str, D));
		if (!flag)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;

	}
	
}
int main()
{
	solution();
	system("pause");
	return 0;
}