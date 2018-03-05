#include<iostream>
#include<string>
#include<vector>
#pragma warning(disable:4996)

using namespace std;
int m;								//M是人数
string in = "24:00:00", out = "00:00:00";
string first, last;

void solution()
{
	string temp, name;
	freopen("1.txt", "r", stdin);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> name;
		//name.push_back(temp);
		cin >> temp;
		if (temp.compare(in) < 0)
		{
			in = temp;
			first = name;
		}
		cin >> temp;
		if (temp.compare(out) > 0)
		{
			out = temp;
			last = name;
		}
	}
	cout << first << ' ' << last;

}

int main(void)
{
	solution();
	system("pause");
	return 0;
}