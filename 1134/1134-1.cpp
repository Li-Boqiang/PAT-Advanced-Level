//#include<iostream>
//#include<vector>
//#include<set>
//#pragma warning(disable:4996)
//using namespace std;
//
//int N, M;
//vector<vector<int>>G;
//
//void solution()
//{
//	cin >> N >> M;
//	G.resize(N);
//	int v1, v2;
//	for (int i = 0; i < M; i++)
//	{
//		scanf("%d %d", &v1, &v2);
//		G[v1].push_back(v2);
//		G[v2].push_back(v1);
//	}
//	int K,Nv;
//	cin >> K;
//	for (int i = 0; i < K; i++)
//	{
//		bool flag = true;
//		scanf("%d", &Nv);
//		//cin >> Nv;
//		set<int>s;
//		for (int j = 0; j < Nv; j++)
//		{
//			scanf("%d", &v1);
//			s.insert(v1);
//		}
//		for (int j = 0; j< N; j++)
//		{
//			if (s.count(j))
//				continue;
//			for (int v = 0; v < G[j].size(); v++)
//				if (!s.count(G[j][v]))
//				{
//					flag = false;
//					break;
//				}
//			if (flag == false)
//				break;
//		}
//		if (flag)
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//}
//
//int main()
//{
//	freopen("1.txt", "r", stdin);
//	solution();
//	system("pause");
//	return 0;
//}