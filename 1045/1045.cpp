#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int N, like[201] = {0}, stripe[10001];
void solution()
{
	int M, L;
	cin >> N >> M;
	int color;
	for (int i = 1; i <= M; i++)
	{
		cin >> color;
		like[color] = i;				//人为的构建颜色的大小关系
	}
	int like_num=0;
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		cin >> color;
		if (like[color])
		{
			stripe[like_num++] = like[color];			//只保存喜欢的，反正不喜欢的也得剪去
		}
	}
	int dp[10001];
	int res = 0;
	for (int i = 0; i < like_num; i++)
	{
		dp[i] = 1;						//至少喜欢一个
		for (int j = 0; j < i; j++)
		{
			if(stripe[j] <= stripe[i])	//需要添加了
				dp[i] = max(dp[i], dp[j] + 1);
		}
		res = max(res, dp[i]);
	}
	cout << res;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}