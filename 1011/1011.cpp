#include<iostream>
#include<iomanip>
#include <algorithm>
#pragma warning(disable:4996)


using namespace std;
double a, b, c;
double res = 1.0;
double temp;
void solution()
{
	for (int i = 0; i < 3; i++)
	{
		cin >> a >> b >> c;
		temp = max(a, max(b, c));
		res *= temp;
		if (temp == a)
			cout << "W ";
		if (temp == b)
			cout << "T ";
		if (temp == c)
			cout << "L ";
	}
	res *= 0.65;
	res--;
	res *= 2;
	cout << fixed << setprecision(2)<<res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}