#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int NC, NP;
vector<long long int>vPnega;			//P中的负数
vector<long long int>vCnega;			//C中的负数
vector<long long int>vPposi;			//P中的正数
vector<long long int>vCposi;			//C中的正数
long long int sum = 0;
void solution()
{
	sort(vPposi.begin(), vPposi.end());
	sort(vCposi.begin(), vCposi.end());
	sort(vPnega.begin(), vPnega.end());
	sort(vCnega.begin(), vCnega.end());
	int j = vCposi.size() - 1;
	for (int i = vPposi.size()-1; i >=0&&j>=0; i--,j--)
	{
		sum += vPposi[i] * vCposi[j];
	}
	j = 0;
	for (int i = 0; i < vPnega.size() && j <vCnega.size(); i++, j++)
	{
		sum += vPnega[i] * vCnega[j];
	}
	cout << sum;
}

int main()
{
	freopen("1.txt", "r", stdin);
	cin >> NC;
	long long int input;
	for (int i = 0; i < NC; i++)
	{
		cin >> input;
		if (input > 0)
			vCposi.push_back(input);
		else if (input < 0)
			vCnega.push_back(input);
	}
	cin >> NP;
	for (int i = 0; i < NP; i++)
	{
		cin >> input;
		if (input > 0)
			vPposi.push_back(input);
		else if (input < 0)
			vPnega.push_back(input);
	}
	solution();
	system("pause");
	return 0;
}
