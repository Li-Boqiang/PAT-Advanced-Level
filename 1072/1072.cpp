#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#pragma warning(disable:4996)
#define MAX_NUM 2147483646
using namespace std;

int N, M, K, Ds;
bool visit[1011] = {0};

void solution()
{
	cin >> N >> M >> K >> Ds;
	vector<vector<int>> g(N + M + 1, vector<int>(N + M + 1, MAX_NUM/2));	//初始化
	for (int i = 1; i <= N+M; i++)
	{
		g[i][i] = 0;				//对角线初始化
	}
	string start_string, end_string;
	int input_dis;
	int start_num, end_num;

	//输入数据
	for (int i = 0; i < K; i++)
	{
		cin >> start_string >> end_string >> input_dis;
		if (start_string[0]=='G')
		{
			start_string=start_string.substr(1);//提取后面的数字
			start_num = stoi(start_string)+N;		//转为数字
		}
		else
		{
			start_num = stoi(start_string);		//转为数字
		}
		if (end_string[0]=='G')
		{
			end_string = end_string.substr(1);
			end_num = stoi(end_string)+N;
		}
		else
		{
			end_num = stoi(end_string);
		}
		g[end_num][start_num] = g[start_num][end_num] = min(g[start_num][end_num], input_dis);
	}
	int res = -1;		//表示未找到
	double res_dis = -1, res_aver =MAX_NUM/2;		//初始化
	for (int start_point = N+1; start_point <= N+M; start_point++)					//对每个位置进行Dij求最短路径
	{
		vector<int> dis = g[start_point];
		fill(visit, visit + 1011, false);
		//dis[start_point] = 0;			//从i开始
		for (int i = 0; i < N+M; i++)			//dij算法
		{
			int u = -1, min_dis = MAX_NUM/2;
			for (int j = 1; j <= N+M; j++)
			{
				if (!visit[j]&&dis[j]<min_dis)
				{
					u = j;
					min_dis = dis[j];			//找到一个最近的
				}
			}
			if (u == -1)
				break;
			visit[u] = true;					//将其标记为访问
			for (int k = 1; k <= N+M; k++)
			{
				if (!visit[k]&&dis[k]>dis[u]+g[u][k])
				{
					dis[k] = dis[u] + g[u][k];		//更新dis数组
				}
			}
		}
		double min_dis=MAX_NUM/2, min_aver=0.0;
		for (int i = 1; i <= N; i++)
		{
			if (dis[i]>Ds)							//有一个超出最大范围都不行
			{
				min_dis = -1;
				break;
			}
			if (dis[i]<min_dis)
			{
				min_dis = dis[i];
			}
			min_aver += 1.0*dis[i];
		}
		if (min_dis==-1)//没找到
		{
			continue;  //下一个加油站
		}
		min_aver /= N;
		if (min_dis>res_dis)						//如果此加油站距离最近的房屋 大于目前已知的最近距离
		{
			res = start_point;//是这个点
			res_dis = min_dis;
			res_aver = min_aver;
		}
		else if (min_dis==res_dis&&min_aver<res_aver)	//距离相同但是平均距离更短
		{
			res = start_point;
			res_aver = min_aver;
		}
		
	}
	if (res==-1)
	{
		cout << "No Solution";
	}
	else
	{
		printf("G%d\n%.1f %.1f", res - N, res_dis, res_aver);
	}

}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}