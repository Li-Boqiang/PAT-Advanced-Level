#include<iostream>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

bool key[256] = {0};
string a, b;
void solution()
{
	cin >> a;
	cin >> b;
	transform(a.begin(), a.end(),a.begin(), ::toupper);
	transform(b.begin(), b.end(),b.begin(), ::toupper);
	for (auto i = a.begin(); i != a.end(); i++)
	{
		if (b.find(*i) == string::npos&&key[*i]==false)
		{
			cout << *i;
			key[*i] = true;
		}
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}