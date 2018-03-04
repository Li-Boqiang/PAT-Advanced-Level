#include<iostream>
#include<string>
using namespace std;

void solution(void)
{
	int a, b, c = 0, d = 0, e = 0;
	cin >> a >> b;
	c = a + b;
	string res;
	res = to_string(c);
	if (c / 1000000)
	{
		cout << c / 1000000 << ',' << res.substr(res.length() - 6, 3) << ',' << res.substr(res.length() - 3, 3) << endl;
	}

	else if (c / 1000)
	{
		cout << c / 1000 << ',' << res.substr(res.length() - 3, 3) << endl;
	}
	else
		cout << c << endl;
}

int main(void)
{
	solution();
	system("pause");
	return 0;
}