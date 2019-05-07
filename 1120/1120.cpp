#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int fID = 0, N;
string num;
map<int, bool>m;
void solution()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num; fID = 0;
		for (int j = 0; j < num.size(); j++)
		{
			fID += (num[j] - '0');
		}
		if (!m.count(fID))
			m[fID] = true;
	}
	vector<int>res;
	for (auto i = m.begin(); i != m.end(); i++)
	{
		res.push_back(i->first);
	}
	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
		if (i != res.size() - 1)
			cout << ' ';
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}