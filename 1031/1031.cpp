//有如下关系
//n1+n2+n3-2=N
//3<=n2<=N
//n1,n3<=n2
//字符在5~80个字符之间，没有空格
//按照描述输出U型的字符

//所以有如下关系	(N+2)能整除3，那么就是n1=n2=n3=(N+2)/3，如果(N+2)%3=1，那么就是n2=n1+1=n3+1  (N+2)%3=2，那么就是n2=n1+2=n3+2

#include<iostream>
#include<string> 
#pragma warning(disable:4996)

using namespace std;

string str;

void solution()
{
	cin>>str;
	int p = (str.size() + 2) % 3;
	int n1, n2, n3;
	n1 = n3 = (str.size() + 2 - p) / 3;
	n2 = n1 + p;
	for (int i = 0; i < n1-1; i++)
	{
		cout << str[i];
		for (int j = 0; j < n2-2; j++)
			cout << ' ';
		cout << str[str.size() - i - 1] << endl;
	}
	for (int i = n1 - 1; i < n1 - 1 + n2; i++)
		cout << str[i];
	cout << endl;
}

int main()
{	
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
