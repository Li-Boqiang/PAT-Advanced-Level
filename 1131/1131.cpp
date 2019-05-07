#include<iostream>
#include<string>
#include<vector>
#include <unordered_map>
#pragma warning(disable:4996)
using namespace std;
int N, M, K;
vector<int> G[10001];
bool visit[10001] = { 0 };
int startStaion, endStation, minCount=99999999, minTrans=99999999;
vector<int>res, tempPath;
unordered_map<int, int> line;

int getTrans(vector<int>path)
{
	int cnt = 0;
	for (int i = 1; i < path.size()-1; i++)
	{
		if (line[path[i - 1]*10000+path[i]] != line[path[i]*10000+path[i+1]])
			cnt++;
	}
	return cnt;
}

void DFS(int station, int cnt)
{
	if (station==endStation)
	{
		if (cnt < minCount || cnt == minCount&&getTrans(tempPath) < minTrans)
		{
			res = tempPath;
			minCount = cnt;
			minTrans = getTrans(tempPath);
		}
		return;
	}
	for (int i = 0; i < G[station].size(); i++)
	{
		if (!visit[G[station][i]])
		{
			visit[G[station][i]] = true;
			tempPath.push_back(G[station][i]);
			DFS(G[station][i], cnt + 1);
			visit[G[station][i]] = false;
			tempPath.pop_back();
		}
	}
}
void solution()
{
	cin >> N;
	int preStation, tempStation;
	for (int i = 1; i <= N; i++)
	{
		cin >> M >> preStation;
		for (int j = 1; j < M; j++)
		{
			cin >> tempStation;
			G[preStation].push_back(tempStation);
			G[tempStation].push_back(preStation);			//表示这两个站连接起来了
			line[preStation*10000+tempStation] = i;
			line[tempStation*10000+preStation] = i;				//记录这两个站的所在的线路
			preStation = tempStation;
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> startStaion >> endStation;
		fill(visit, visit + 10001, 0);
		tempPath.clear(); minCount = 99999999; minTrans = 99999999;
		visit[startStaion] = true;
		tempPath.push_back(startStaion);
		DFS(startStaion, 0);
		cout << minCount << endl;
		for (int i = 0; i < res.size(); i++)
		{
			if (res[i] == startStaion || res[i] == endStation || line[res[i - 1]*10000+res[i]] != line[res[i]*10000+ res[i + 1]])
			{
				if (res[i] != startStaion)
					printf("%04d.\n", res[i]);
				if (res[i] != endStation)
					printf("Take Line#%d from %04d to ", line[res[i]*10000+ res[i + 1]], res[i]);
			}
		}
	}

}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}