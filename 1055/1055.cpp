//排序规则是财富从高到低。
//年龄从小到大。

#include<iostream>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int N, K, M, Amin, Amax;		//N是总人数，K是查询数，M是输出数量，剩下的是年龄区间
struct node
{
	string Name;
	int Age;
	int Worth;
}Rich[100001];

bool comp(const struct node &a, const struct node &b)
{//按照净资产，年龄，姓名 排序
	if (a.Worth != b.Worth)
		return a.Worth > b.Worth;		//从大到小排序
	else if (a.Age != b.Age)
		return a.Age < b.Age;
	else
		return a.Name < b.Name;
}

void solution()
{
	int RealRank[201*100];
	int RankCount = 0;						//用于记录输出排名
	cin >> N >> K;
	int AgeRank[201] = { 0 };				//最大200岁，开个201的数组
	for (int i = 0; i < N; i++)
		cin >> Rich[i].Name >> Rich[i].Age >> Rich[i].Worth;
	sort(Rich, Rich + N, comp);		//	排序
	for (int i = 0; i < N; i++)
	{
		AgeRank[Rich[i].Age]++;
		if (AgeRank[Rich[i].Age] < 101)
			RealRank[RankCount++] = i;	//i是Rich中的标号，只需要记录其标号即可
	}
	int age, num = 0;					//用于记录输出数量，num<M
	for (int i = 1; i <= K; i++)
	{
		cin >> M >> Amin >> Amax;
		cout << "Case #" << i << ':' << endl;
		num = 0;				
		for (int j = 0; j < RankCount&&num<M; j++)
		{
			age = Rich[RealRank[j]].Age;
			if (Amin<=age&&age<=Amax)		//在年龄范围内的人
			{
				cout << Rich[RealRank[j]].Name << ' ' << Rich[RealRank[j]].Age << ' ' << Rich[RealRank[j]].Worth << endl;
				num++;
			}
		}
		//所有的都搜寻完毕后
		if (!num)					//没人
			cout << "None" << endl;
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}