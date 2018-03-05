//注意一下特殊情况，0	0.0123	0.0		01.123 00.010

#include<iostream>
#include<string>
#pragma warning(disable:4996)

using namespace std;

int N;						//表示有效数字的位数

struct node
{
	string Number;
	int zhishu;
	
	string Standard="0.";
}a,b;

node Tras(node str)
{
	int FirstYouxiaoshuzi = -1;
	int PointWeizhi = -1;
	int Count = 0;
	for (int i = 0; i < str.Number.length(); i++)
	{
		if (str.Number[i]=='.')
		{
			PointWeizhi = i;
			continue;
		}
		else if(str.Number[i]=='0'&&FirstYouxiaoshuzi==-1)
		{
			continue;
		}
		else
		{
			if (FirstYouxiaoshuzi == -1)
				FirstYouxiaoshuzi = i;
			if (Count<N)
			{
				str.Standard += str.Number[i];
				Count++;
			}

		}
	}
	if (Count == 0)												//没有有效数字,也要按照要求的格式进行输出
	{
		
		for (int i = 0; i < N; i++)
		{
			str.Standard += "0";
		}
		str.zhishu = 0;
		return str;
	}
	else
	{
		for (int i = Count; i < N; i++)
			str.Standard += "0";
	}
	if (PointWeizhi == -1)										//没有找到小数点，就是整数
	{
		PointWeizhi = str.Number.length();
	}
	if (PointWeizhi - FirstYouxiaoshuzi < 0)
		str.zhishu = PointWeizhi - FirstYouxiaoshuzi + 1;
	else
		str.zhishu = PointWeizhi - FirstYouxiaoshuzi;
	
	
	return str;

}

void solution()
{
 	cin >> N >> a.Number >> b.Number;
	a = Tras(a);
	b = Tras(b);
	if (a.Standard == b.Standard&&a.zhishu==b.zhishu)
		cout << "YES " << a.Standard << "*10^" << a.zhishu << endl;
	else
		cout << "NO " << a.Standard << "*10^" << a.zhishu << ' ' << b.Standard << "*10^" << b.zhishu << endl;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}