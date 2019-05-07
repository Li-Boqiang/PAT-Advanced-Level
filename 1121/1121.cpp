#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int N, num1, num2;
map<int, int>couple;
map<int, bool>f;
vector<int>res,temp;
void solution()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num1 >> num2;
		couple[num1] = num2;
		couple[num2] = num1;
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num1;
		f[num1] = true;
		temp.push_back(num1);
	}
	for (int i = 0; i < temp.size(); i++)
	{
		if (!f.count(couple[temp[i]]))
			res.push_back(temp[i]);
	}
	cout << res.size() << endl;
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++)
	{
		printf("%05d", res[i]);
		//cout << res[i];
		if (i!=res.size()-1)
		{
			cout << ' ';
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