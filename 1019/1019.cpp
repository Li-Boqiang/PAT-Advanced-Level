//计算在给定进制下的回文数
//方法很简答，将给的10进制的数转为N进制的数
//输出第一行是是否是回文数
//第二行是将其改为N进制
#include<iostream>
#include<string>

//#pragma warning(disable:4996)
using namespace std;

unsigned long int Number, N;
int Result[110];
int trans = 0;

bool Check()
{
	bool Flag = true;
	int i = 0, j = trans-1;

	while (i < j)
		if (Result[i++] != Result[j--])
			Flag = false;
	return Flag;
}

void solution()
{
	cin >> Number >> N;
	char temp;
	if (Number == 0)
		Result[trans++] = 0;
	while (Number != 0)
	{
		Result[trans++] = Number%N;
		Number /= N;
	}
	if (Check())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (int i = trans - 1; i > 0; i--)
		cout << Result[i] << ' ';
	cout << Result[0] << endl;
}

int main()
{
	solution();
	system("pause");
	return 0;
}