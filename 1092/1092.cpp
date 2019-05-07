#include<iostream>
#include<string>
#pragma warning(disable:4996)
using namespace std;

int res[256] = { 0 };

string a, b;
int cnt = 0;
void solution()
{
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++)
		res[a[i]]++;
	for (int i = 0; i < b.size(); i++)
	{
		if (res[b[i]] > 0)
			res[b[i]]--;
		else
			cnt++;
	}
	if (cnt == 0)
		cout << "Yes " << a.size() - b.size();
	else
		cout << "No " << cnt;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}