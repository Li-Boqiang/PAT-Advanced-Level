#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#pragma warning(disable:4996)
using namespace std;

int P, M, N;
map<string, int>yingshe;
typedef struct 
{
	string ID;
	int Gp = 0;
	int Gm = -1;
	int Gf = 0;
	int zongfen = 0;
}node;
vector<node>chengji;
bool cmp(node a, node b)
{
	if (a.zongfen == b.zongfen)
		return a.ID < b.ID;
	else
		return a.zongfen > b.zongfen;
}
void solution()
{
	cin >> P >> M >> N;
	string mingzi;
	int cnt = 0,score;
	chengji.resize(P);
	for (int i = 0; i < P; i++)
	{
		cin >> mingzi >> score;
		if (score >= 200)						//大于200分才记录下来
		{
			yingshe[mingzi] = cnt++;
			chengji[yingshe[mingzi]].Gp = score;			//记录成绩
			chengji[yingshe[mingzi]].ID = mingzi;			//记录名字	
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> mingzi >> score;
		if (yingshe.count(mingzi))				//如果名字存在
			chengji[yingshe[mingzi]].Gm = score;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> mingzi >> score;
		if (yingshe.count(mingzi))
			chengji[yingshe[mingzi]].Gf = score;
	}
	for (int i = 0; i < cnt; i++)
	{
		if (chengji[i].Gm > chengji[i].Gf)
			chengji[i].zongfen = (int)(chengji[i].Gm*0.4 + chengji[i].Gf*0.6 + 0.5);
		else
			chengji[i].zongfen = chengji[i].Gf;
	}
	sort(chengji.begin(), chengji.end(), cmp);
	for (int i = 0; i < cnt&&chengji[i].zongfen>=60; i++)
		cout << chengji[i].ID << ' ' << chengji[i].Gp << ' ' << chengji[i].Gm << ' ' << chengji[i].Gf << ' '<< chengji[i].zongfen<<endl;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}