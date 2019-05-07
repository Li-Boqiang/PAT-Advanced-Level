#include<iostream>
#include<vector>
#include<math.h>
#pragma warning(disable:4996)
using namespace std;

int N, K, P, sum = 0, maxsum = 0, upbound;
vector<int> v, temp, res;

bool DFS(int s,int cur)		//cur表示目前找打了多少个数
{
	if (cur==K)				//找到了K个数
	{
		if (s==0)			//s表示目前还剩多少
		{
			sum = 0;
			for (int i = 0; i < temp.size(); i++)
				sum += temp[i];
			if (sum>maxsum)									//sum表示当前序列各个数的和，只保留最大的
			{
				res = temp;
				maxsum = sum;
			}
			return true;
		}
		else return false;
	}
	upbound = cur > 0 ? temp[cur - 1] : v.size() - 1;		//由于是先找大的，因此就从大向小去找，upbound表示查找的上界
	for (int i = upbound; i >= 1; i--)
	{
		if (v[i] <= s)
		{
			temp[cur] = i;
			DFS(s - v[i], cur + 1);
		}
		else if (i == 1)
			return false;
	}
	return true;
}
void solution()
{
	cin >> N >> K >> P;
	v.push_back(0); temp.resize(K);
	for (int i = 1; pow(i, P) <= N; i++)
		v.push_back(pow(i, P));
	DFS(N, 0);
	if (res.size() == K)						//只有找到了K个数才输出
	{
		cout << N << " = ";
		printf("%d^%d", res[0], P);
		for (int i = 1; i < res.size(); i++)
			printf(" + %d^%d", res[i], P);
	}
	else
		cout << "Impossible";
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}