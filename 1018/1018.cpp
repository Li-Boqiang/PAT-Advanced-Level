//图，需要知道一共有多少条最短路径
//输出发送自行车数量最小的那条路径
//在有多条最短路径的情况下，由于发送自行车是根据第一个节点来确定的，相当于简便了一些
//在最后，需要将多余的自行车收回。
//举例：如果第一个节点有1个自行车，最后一个节点有10个自行车。
//那么是send4，收回5个。这个顺序是不能颠倒的。
//也就是不能把最后一个节点的自行车匀给前面的节点，是单向路径
//也就是对于每个节点，需要保存最短路径（的上一/多节点）。
//需要保存在运输过程中流动的自行车的数量
//DFS算法，从0节点开始依次求各个节点DFS，直到找到了目标节点，保存每次的路径
#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
#define MAX 999999
int CMax, N, Sp, M;			//Cmax是节点最多有多少自行车
							//N是Station的数量，Sp是问题车站
							//M是路的条数
struct node
{
	int distance;
	int BikeSend;
	int BikeReceive;
	int path[501];
}Search,result;

int Road[501][501];
bool visit[501] = { false };		//默认为没有访问的状态
int Station[501];			//各个车站的自行车数量
int Count = 0;

void DFS(int StartPoint)
{
	if (StartPoint==Sp)			//找到了一条路径
	{
		if (Search.distance<result.distance)		//如果是最短的
		{
			result = Search;
		}
		else if(Search.distance==result.distance)
		{
			if (Search.BikeReceive<result.BikeReceive)
			{
				result = Search;
			}
			else if (Search.BikeReceive==result.BikeReceive)
			{
				if(Search.BikeSend<result.BikeSend)
					result=Search;
			}
		}
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visit[i]&&Road[i][StartPoint]!=MAX)
		{
			visit[i] = true;
			node temp;
			temp.distance = Search.distance;
			temp.BikeReceive = Search.BikeReceive;
			temp.BikeSend = Search.BikeSend;				//保存这一层的信息
			Search.distance += Road[i][StartPoint];
			int Move = Station[i] - CMax / 2;				//如果大于零，表示要把自行车送走一部分，自行车多了
			if (Move>=0)
			{
				Search.BikeSend += Move;
			}
			else
			{												//否则就是自行车少了，需要接收自行车
				Move = -Move;
				if (Move<=Search.BikeSend)
				{
					Search.BikeSend -= Move;				
				}
				else
				{
					Search.BikeReceive += (Move - Search.BikeSend);			//接受的自行车只增不减，因为是单向传递
					Search.BikeSend = 0;					
				}
			}
			Count++;
			Search.path[Count] = i;				//保存当前路径
			DFS(i);
			Count--;
			Search.distance = temp.distance;
			Search.BikeReceive = temp.BikeReceive;
			Search.BikeSend = temp.BikeSend;
			visit[i] = false;
		}
	}
}
void solution()
{
	fill(Road[0], Road[0] + 501 * 501, MAX);
	cin >> CMax >> N >> Sp >> M;
	int road_a, road_b;			//路的下标
	int station_temp;			
	for (int i = 1; i <= N; i++)//管理站是0号
	{
		cin>>Station[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> road_a >> road_b;
		cin >> Road[road_a][road_b];
		Road[road_b][road_a] = Road[road_a][road_b];
	}
	//输入完全部的信息
	Search.distance = 0;Search.BikeReceive = 0;Search.BikeSend = 0;
	result.distance = MAX; result.BikeReceive = MAX; result.BikeSend = MAX;
	DFS(0);
	cout << result.BikeReceive << " 0";
	for (int i = 1; result.path[i]!=Sp; i++)
	{
		cout << "->" << result.path[i];
	}
	cout << "->" << Sp << " " << result.BikeSend << endl;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}