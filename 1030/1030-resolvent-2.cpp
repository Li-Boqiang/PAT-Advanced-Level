//这道题和1003题，Emergency非常像
//和1018题也非常像
//思路1，使用DFS，找出所有的路，保存路径最短且花费最少的。
//思路2，先用dij算法求出到各个点的最短路径，再用DFS遍历找出在最短路径上且花费最少的
//以下思路是帅帅的解法2：
#include<iostream>
#pragma warning(disable:4996)
#define MAX 9999999
using namespace std;

int CityNumber, HighwayNumber, StartCity, EndCity;			//城市的数量，高速公路的条数，起始城市和终止城市
int Road[501][501];
int Cost[501][501];											//花费矩阵
bool visit[501] = { false };
int Distance[501];
struct node
{
	int Path[501];
	int huafei = 0;
}Search, Result;
int Count = 0;

void DFS(int StartPoint)
{
	if (StartPoint == EndCity)
	{
		if (Search.huafei < Result.huafei)					//肯定是最短路径，只需要比较花费就好了
		{
			Search.Path[Count] = EndCity;
			Result = Search;
			Search.huafei = 0;

			Count = 0;
		}
		return;
	}

	Search.Path[Count] = StartPoint;
	for (int i = 0; i < CityNumber; i++)
	{
		if (Distance[i] == Distance[StartPoint] + Road[StartPoint][i])		//表示正好在最短路径上
		{
			Search.huafei += Cost[StartPoint][i];		//花费加上
			Count++;
			DFS(i);
		}
	}
}


void Dij()
{
	cin >> CityNumber >> HighwayNumber >> StartCity >> EndCity;
	fill(Road[0], Road[0] + 501 * 501, MAX);									//初始化
	fill(Distance, Distance + 501, MAX);
	int road_a, road_b;
	for (int i = 0; i < HighwayNumber; i++)
	{
		cin >> road_a >> road_b;
		cin >> Road[road_a][road_b];
		Road[road_b][road_a] = Road[road_a][road_b];
		cin >> Cost[road_a][road_b];
		Cost[road_b][road_a] = Cost[road_a][road_b];
	}
	//输入完所有的信息
	//初始化

	int min = MAX;
	int k;											//Dij算法中保存临时信息
	for (int i = 0; i < CityNumber; i++)
	{
		Distance[i] = Road[StartCity][i];
	}
	Distance[StartCity] = 0;
	for (int i = 0; i < CityNumber; i++)
	{
		min = MAX;
		for (int j = 0; j < CityNumber; j++)
		{
			if (!visit[j] && Distance[j] < min)
			{
				k = j;
				min = Distance[j];
			}
		}											//找到当前最近的
		visit[k] = true;							//标记为访问

		for (int j = 0; j < CityNumber; j++)
		{
			if (!visit[j] && min + Road[k][j]<Distance[j])
			{
				Distance[j] = min + Road[k][j];
			}
		}
	}
	//现在Distance数组里保存的是从StartPoint到各个点的最短路径的长度
}

int main()
{
	freopen("1.txt", "r", stdin);
	Dij();
	Result.huafei = MAX;
	DFS(StartCity);
	for (int i = 0; Result.Path[i] != EndCity; i++)
		cout << Result.Path[i] << ' ';
	cout << EndCity << ' ' << Distance[EndCity] << ' ' << Result.huafei << endl;
	system("pause");
	return 0;
}