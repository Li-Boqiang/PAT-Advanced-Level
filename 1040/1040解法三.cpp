#include<iostream>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;
string str;
int length = 1;
bool dp[1010][1010];//str[i]~str[j]是否对称，1是，0不是
void solution()
{
	int n = str.size();
	//初始化
	for (int i = 0; i < n; i++)
	{
		dp[i][i] = 1;
		if (i<n-1&&str[i]==str[i+1])
		{
			dp[i][i + 1] = 1;
			length = 2;
		}
	}
	for (int i = 1; i <n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (str[i]==str[j]&&dp[j+1][i-1]==true)
			{
				dp[j][i] = true;
				if (i - j + 1 > length)
					length = i - j + 1;
			}
		}
	}
	cout << length;
}

int main()
{
	freopen("1.txt", "r", stdin);
	getline(cin, str);
	solution();
	system("pause");
	return 0;
}