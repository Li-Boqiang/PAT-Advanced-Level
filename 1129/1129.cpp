#include<iostream>
#include<set>
#pragma warning(disable:4996)
using namespace std;

int info[50001] = { 0 };
struct node
{
	int ID, cnt;
	bool operator < (const node &a) const
	{
		if (cnt == a.cnt)
			return ID < a.ID;
		else
			return cnt > a.cnt;
	}
};
int N, K, temp;
set<node> s;
void solution()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		if (i!=0)
		{
			printf("%d:", temp);
			int tempcnt = 0;
			for (auto it = s.begin(); it != s.end()&&tempcnt<K; it++)
			{
				printf(" %d", it->ID);
				tempcnt++;
			}
			cout << endl;
		}
		auto it = s.find(node{ temp,info[temp] });
		if (it != s.end())
			s.erase(it);
		info[temp]++;
		s.insert(node{ temp,info[temp] });
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}