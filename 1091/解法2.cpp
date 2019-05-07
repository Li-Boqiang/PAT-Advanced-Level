#include<iostream>
#include<queue>
#pragma warning(disable:4996)
using namespace std;

typedef struct 
{
	int x, y, z;
}location;
queue<location> que;
int neighbor[3][6] =
{
	{ 1, 0, 0, -1, 0, 0 },
	{ 0, 1, 0, 0, -1, 0 },
	{ 0, 0, 1, 0, 0, -1 }
};
int Brain[1300][130][80];
int M, N, L, T, res=0, temp=0;
void BFS()
{
	while (!que.empty())
	{
		location l = que.front(); que.pop();
		if (Brain[l.x][l.y][l.z] == 1)
		{
			temp++;
			Brain[l.x][l.y][l.z] = 0;
			for (int i = 0; i < 6; i++)
			{
				int x1 = l.x + neighbor[0][i];
				int y1 = l.y + neighbor[1][i];
				int z1 = l.z + neighbor[2][i];
				if (x1 >= 0 && x1<M&&y1 >= 0 && y1<N&&z1 >= 0 && z1<L)
				{
					que.push({ x1,y1,z1 });
				}
			}
		}
	}
}


void solution()
{
	cin >> M >> N >> L >> T;
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < N; k++)
			{
				scanf("%d", &Brain[j][k][i]);
			}
		}
	}
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (Brain[j][k][i]==1)
				{
					temp = 0;
					que.push({ j,k,i });
					BFS();
					if (temp>=T)
					{
						res += temp;
					}
				}
			}
		}
	}
	cout << res;
}
int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}