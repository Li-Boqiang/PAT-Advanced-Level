#include<iostream>
#include <iomanip>
using namespace std;

float a[1001] = { 0 }, b[1001] = { 0 }, c[1001] = { 0 };   //数组的内标表示指数,输入和输出要求指数依次下降

void solution()
{
	int k, n, res = 0, zs[20];
	float xs[20];
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> n;
		cin >> a[n];
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> n;
		cin >> b[n];
	}

	for (int i = 1000; i >= 0; i--)
	{
		c[i] = a[i] + b[i];
		if (c[i] != 0)
		{
			zs[res] = i;
			xs[res] = c[i];
			res++;
		}
	}
	cout << res;
	for (int i = 0; i < res; i++)
	{
		cout << fixed << setprecision(1) << ' ' << zs[i] << ' ' << xs[i];
	}

}

int main(void)
{
	solution();
	system("pause");
	return 0;
}