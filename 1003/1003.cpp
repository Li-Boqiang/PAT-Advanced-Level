//迪杰斯特拉算法  和乘法原理
//1003

#include<iostream>
#include<algorithm>
#define MAX 99999999				//设定999999为无限远
#pragma warning(disable:4996)

using namespace std;

int person[501];
int road[501][501];

void solution()
{
	freopen("input.txt", "r", stdin);
	int n, m, start, end;
	int road_a, road_b;
	int visit[501] = { 0 };		//默认为没有访问的状态
	int number[501] = { 0 };	//number是最短路的条数
	int dis[501];				//dis是dij算法中，起点到其他城市的最短路径
	int rescue[501] = { 0 };	//保存目前为止，走过的城市中，救援队数量最多的
	int min, k;					//用于在dij算法中的循环


	fill(road[0], road[0] + 501 * 501, MAX);
	fill(dis, dis + 501, MAX);
	//输入第一行的值    n是城市的数量，m是路的条数，start是起始城市，end是终点
	cin >> n >> m >> start >> end;	
	for (int i = 0; i < n; i++)
	{
		//输入救援队的值
		cin >> person[i];		
	}
	//M条路，输入这个图的编标信息
	for (int i = 0; i < m; i++)		
	{
		cin >> road_a >> road_b;
		cin >> road[road_a][road_b];
		road[road_b][road_a] = road[road_a][road_b];
	}


	//初始化，将start城市访问标记1，rescue救援队的数量，dis数组保存
	//visit[start] = 1;
	rescue[start] = person[start];
	number[start] = 1;
	for (int i = 0; i < n; i++)
	{
		dis[i] = road[start][i];
	}
	dis[start] = 0;

	//主循环
	for (int i = 0; i < n; i++)
	{
		min = MAX;
		for (int j = 0; j < n; j++)
		{
			//先找出距离start最短的点
			if (!visit[j] && dis[j] < min)		
			{ 
				k = j;
				min = dis[j];
			}		
		}
		
		//这个点就被访问了，第一个k是start点本身自己，第一个min是0
		visit[k] = 1;	
		


		for (int j = 0; j < n; j++)
		{
			if (!visit[j]&&(min+road[k][j]<dis[j]))
			{
				dis[j] = min + road[k][j];
				number[j] = number[k];
				rescue[j] = rescue[k] + person[j];
			}
			else if (!visit[j]&&(min+road[k][j])==dis[j]&&road[k][j]!=MAX)
			{
				number[j] += number[k];
				if (rescue[k]+person[j]>rescue[j])
				{
					rescue[j] = rescue[k] + person[j];
				}
			}
		}
	}
	//这个时候，dis数组里保存的是从start点开始到各个点的最短路径的长度。
	cout << number[end] << ' ' << rescue[end];

}

int main(void)
{
	solution();
	system("pause");
	return 0;
}