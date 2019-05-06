#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int N, need;
float res = 0.0;
typedef struct
{
	float weight;								//每种的重量并不一定都是整数
	float TotalPrice;
	float UnitPrice;
}Mooncake;
vector<Mooncake> mooncake;
bool cmp(Mooncake a, Mooncake b)
{
	return a.UnitPrice > b.UnitPrice;
}
void solution()
{
	cin >> N >> need;
	mooncake.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> mooncake[i].weight;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> mooncake[i].TotalPrice;
		mooncake[i].UnitPrice = mooncake[i].TotalPrice / mooncake[i].weight;
	}
	sort(mooncake.begin(), mooncake.end(), cmp);
	for (int i = 0; i<N; i++)					//可能最后全卖完还无法达到需求
	{
		if (need>mooncake[i].weight)
		{
			need -= mooncake[i].weight;
			res += mooncake[i].TotalPrice;
		}
		else
		{
			res += mooncake[i].UnitPrice*need;
			need = 0;
			break;								//够了就跳出循环
		}
	}
	printf("%.2f", res);
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}