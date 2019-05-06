#include<iostream>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

string input;
int a, b, c=-1;
bool cmp(char a, char b)
{
	return a > b;
}
void solution()
{
	cin >> input;
	input.insert(0, 4 - input.length(), '0');

	while (c!=6174&&c!=0)
	{
		sort(input.begin(), input.end());
		a = stoi(input);			//从小到大
		sort(input.begin(), input.end(), cmp);
		b = stoi(input);
		c = b - a;
		printf("%04d - %04d = %04d\n", b, a, c);
		input = to_string(c);
		input.insert(0, 4 - input.length(), '0');
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
