#include<iostream>
#include<string>8
#pragma warning(disable:4996)

using namespace std;

void solution()
{
	string a, b;
	//char a[10001], b[10001];
	//cin >> a >> b;
	getline(cin, a, '\n');
	getline(cin, b, '\n');
	bool b_char[10001] = {0};
	for (int i = 0; i < b.length(); i++)
	{
		b_char[b[i]] = 1;
	}
	for (int i = 0; i < a.length(); i++)
	{
		if (b_char[a[i]]==0)
		{
			cout << a[i];
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