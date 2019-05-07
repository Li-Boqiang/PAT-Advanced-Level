#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;
unordered_map<int, bool>G1;
typedef struct
{
	int a;
	int b;
}node;
bool cmp(node a, node b)
{
	if (a.a != b.a)
		return a.a < b.a;
	else
		return a.b < b.b;
}
int N, M;
bool gender[10001] = { 0 };				//0表示女性，1表示男性
vector<int>G[10001];
vector<node>res;
void solution()
{
	cin >> N >> M;
	vector<int>G[10001];			//邻接表
	string s1, s2;
	int v1, v2;
	while (M--)
	{
		cin >> s1 >> s2;
		v1 = atoi(s1.c_str()); v2 = atoi(s2.c_str());
		v1 = abs(v1); v2 = abs(v2);
		gender[v1] = s1[0] == '-' ? 0 : 1;
		gender[v2] = s2[0] == '-' ? 0 : 1;;
		G[v1].push_back(v2); G[v2].push_back(v1);
		G1[v1*10000+v2]= true; G1[v2*10000+v1] = true;
	}
	int K; cin >> K;
	while (K--)
	{
		res.clear();
		cin >> v1 >> v2;
		v1 = abs(v1); v2 = abs(v2);
		if (gender[v1] ^ gender[v2])			//性别不同
		{
			for (int i = 0; i < G[v1].size(); i++)
				if (gender[G[v1][i]] == gender[v1])				//性别相同
					for (int j = 0; j < G[v2].size(); j++)
						if (gender[G[v2][j]] == gender[v2])		//性别相同
							if (G1[G[v1][i]*10000+ G[v2][j]] == true && gender[G[v1][i]] != gender[G[v2][j]])
								res.push_back({ G[v1][i] ,G[v2][j] });
		}
		else
		{
			for (int i = 0; i < G[v1].size(); i++)
				if (gender[G[v1][i]] == gender[v1] && G[v1][i] != v2)
					for (int j = 0; j < G[v2].size(); j++)
						if (gender[G[v2][j]] == gender[v2] && G[v2][j] != v1)
							if (G1[G[v1][i]*10000+ G[v2][j]] == true && gender[G[v1][i]] == gender[G[v2][j]])
								res.push_back({ G[v1][i] ,G[v2][j] });
		}
		sort(res.begin(), res.end(), cmp);
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++)
			printf("%04d %04d\n", res[i].a, res[i].b);
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
