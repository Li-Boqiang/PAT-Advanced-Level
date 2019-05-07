//#include<iostream>
//#include<stack>
//#pragma warning(disable:4996)
//using namespace std;
//
//int Brain[1300][130][80];
//int M, N, L, T;
//int search = 0;
//int neighbor[6][3] = 
//{
//	{0,0,1},
//	{0,0,-1},
//	{0,1,0},
//	{0,-1,0},
//	{1,0,0},
//	{-1,0,0}
//};
//typedef struct 
//{
//	int x, y, z;
//}location;
//stack<location> sta;
//void DFS()
//{
//	while (!sta.empty())
//	{
//		location l = sta.top();	sta.pop();
//		if (Brain[l.x][l.y][l.z] == 1)
//		{
//			search++;
//			Brain[l.x][l.y][l.z] = 0;
//			for (int i = 0; i < 6; i++)
//			{
//				int x1 = l.x + neighbor[i][0];
//				int y1 = l.y + neighbor[i][1];
//				int z1 = l.z + neighbor[i][2];
//				if (x1 >= 0 && x1<M&&y1 >= 0 && y1<N&&z1 >= 0 && z1<L)
//				{
//					sta.push({ x1,y1,z1 });
//				}
//			}
//		}
//	}
//}
//
//
//void solution()
//{
//	cin >> M >> N >> L >> T;
//	for (int i = 0; i < L; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			for (int k = 0; k < N; k++)
//			{
//				scanf("%d", &Brain[j][k][i]);
//				//cin >> Brain[j][k][i];
//			}
//		}
//	}
//	int res = 0;
//	for (int i = 0; i < L; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			for (int k = 0; k < N; k++)
//			{
//				if (Brain[j][k][i] == 1)
//				{
//					search = 0;
//					sta.push({ j,k,i });
//					DFS();
//					if (search>=T)
//					{
//						res += search;
//					}
//				}
//			}
//		}
//	}
//	cout << res;
//}
//
//int main()
//{
//	freopen("1.txt", "r", stdin);
//	solution();
//	system("pause");
//	return 0;
//}