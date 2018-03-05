//这道题和1003题，Emergency非常像
//和1018题也非常像
//思路1，使用DFS，找出所有的路，保存路径最短且花费最少的。
//思路2，先用dij算法求出到各个点的最短路径，再用DFS遍历找出在最短路径上且花费最少的
//以下内容是萌萌的思路1：
#include<iostream>
#pragma warning(disable:4996)
#define MAX 9999999
using namespace std;

int CityNumber, HighwayNumber, StartCity, EndCity;			//城市的数量，高速公路的条数，起始城市和终止城市
int Road[501][501];
int Cost[501][501];											//花费矩阵
bool visit[501] = { false };
int Count = 0;
struct node
{
	int distance;
	int Cost_total;
	int Path[501];
}Search,result,temp;

void DFS(int StartPoint)
{
	if (StartPoint==EndCity)
	{
		if (Search.distance < result.distance)
			result = Search;
		else if (Search.distance==result.distance)
		{
			if (Search.Cost_total<result.Cost_total)
			{
				result = Search;
			}
		}
		return;
	}

	for (int i = 0; i < CityNumber; i++)					//从0~N-1编号
	{
		if (!visit[i]&&Road[i][StartCity]!=MAX)
		{
			visit[i] = true;
			node temp;
			temp.distance = Search.distance;
			temp.Cost_total = Search.Cost_total;
			Search.distance += Road[i][StartPoint];
			Search.Cost_total += Cost[i][StartPoint];
			Count++;
			Search.Path[Count] = i;
			DFS(i);
			Count--;
			Search.distance = temp.distance;
			Search.Cost_total = temp.Cost_total;
			visit[i] = false;
		}
	}
}



void solution()
{
	cin >> CityNumber >> HighwayNumber >> StartCity >> EndCity;
	fill(Road[0], Road[0] + 501 * 501, MAX);									//初始化
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
	Search.Cost_total = 0; Search.distance = 0;
	result.Cost_total = MAX; result.distance = MAX;
	visit[StartCity] = true;
	DFS(StartCity);
	cout << StartCity;
	for (int i = 1; result.Path[i]!=EndCity; i++)
	{
		cout <<' '<< result.Path[i];
	}
	cout << ' ' << EndCity;
	cout << ' ' << result.distance << ' ' << result.Cost_total;

}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}