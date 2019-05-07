//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<unordered_map>
//#pragma warning(disable:4996)
//using namespace std;
//bool G1[310][310] = { 0 };
//typedef struct
//{
//	int a;
//	int b;
//}node;
//bool cmp(node a, node b)
//{
//	if (a.a != b.a)
//		return a.a < b.a;
//	else
//		return a.b < b.b;
//}
//int N, M;
//bool gender[310] = { 0 };				//0表示女性，1表示男性
//vector<int>G[310];
//vector<node>res;
//unordered_map<int, int>yingshe,niyingshe;
//int cnt = 1;
//void solution()
//{
//	cin >> N >> M;
//	vector<int>G[10001];			//邻接表
//	string s1, s2;
//	int v1, v2;
//	while (M--)
//	{
//		cin >> s1 >> s2;
//		v1 = atoi(s1.c_str());v2 = atoi(s2.c_str());
//		v1 = abs(v1); v2 = abs(v2);
//		if (!yingshe.count(v1))							//逐个重新编号
//		{
//			yingshe[v1] = cnt;
//			niyingshe[cnt++] = v1;
//		}
//		if (!yingshe.count(v2))							//逐个重新编号
//		{
//			yingshe[v2] = cnt;
//			niyingshe[cnt++] = v2;
//		}
//
//		gender[yingshe[v1]] = s1[0] == '-' ? 0 : 1;
//		gender[yingshe[v2]] = s2[0] == '-' ? 0 : 1;
//		G[yingshe[v1]].push_back(yingshe[v2]); G[yingshe[v2]].push_back(yingshe[v1]);
//		G1[yingshe[v1]][yingshe[v2]] = true; G1[yingshe[v2]][yingshe[v1]] = true;
//	}
//	int K; cin >> K;
//	while (K--)
//	{
//		res.clear();
//		cin >> v1 >> v2;
//		v1 = abs(v1); v2 = abs(v2);
//		if (gender[yingshe[v1]] ^ gender[yingshe[v2]])			//性别不同
//		{
//			for (int i = 0; i < G[yingshe[v1]].size(); i++)
//				if (gender[G[yingshe[v1]][i]] == gender[yingshe[v1]])				//性别相同
//					for (int j = 0; j < G[yingshe[v2]].size(); j++)
//						if (gender[G[yingshe[v2]][j]] == gender[yingshe[v2]])		//性别相同
//							if (G1[G[yingshe[v1]][i]][G[yingshe[v2]][j]] == true&&gender[G[yingshe[v1]][i]]!=gender[G[yingshe[v2]][j]])
//								res.push_back({ niyingshe[G[yingshe[v1]][i]] ,niyingshe[G[yingshe[v2]][j]] });
//		}
//		else
//		{
//			for (int i = 0; i < G[yingshe[v1]].size(); i++)
//				if(gender[G[yingshe[v1]][i]] == gender[yingshe[v1]]&&G[yingshe[v1]][i]!= yingshe[v2])
//					for (int j = 0; j < G[yingshe[v2]].size(); j++)
//						if (gender[G[yingshe[v2]][j]] == gender[yingshe[v2]]&&G[yingshe[v2]][j]!= yingshe[v1])
//							if (G1[G[yingshe[v1]][i]][G[yingshe[v2]][j]] == true && gender[G[yingshe[v1]][i]] == gender[G[yingshe[v2]][j]])
//								res.push_back({niyingshe[ G[yingshe[v1]][i]] ,niyingshe[G[yingshe[v2]][j]] });
//		}
//		sort(res.begin(), res.end(), cmp);
//		cout << res.size() << endl;
//		for (int i = 0; i < res.size(); i++)
//			printf("%04d %04d\n", res[i].a, res[i].b);
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