//进制转换，就是将10进制转为13进制。
#include<iostream>
#include<string>
#pragma warning(disable:4996)

using namespace std;
int color_Ten[3];			//十进制的颜色
char Color[7];

void solution()
{
	for (int i = 0; i < 3; i++)
	{	
		cin >> color_Ten[i];
		if (color_Ten[i] / 13 > 9)
			Color[2 * i] = color_Ten[i] / 13 - 10 + 'A';
		else
			Color[2 * i] = color_Ten[i] / 13 + '0';
		if (color_Ten[i] % 13 > 9)
			Color[2 * i + 1] = color_Ten[i] % 13 - 10 + 'A';
		else
			Color[2 * i + 1] = color_Ten[i] % 13 + '0';
	}
	cout << '#';
	for (int i = 0; i < 6; i++)
		cout << Color[i];
	cout << endl;
}


int main()
{
	//freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
