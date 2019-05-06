#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
typedef struct 
{
	int weight;
	vector<int>child;
}node;

vector<node>T;
vector<int>path;
int N, M, S, ID, K, temp;
bool cmp(int a, int b)
{
	return T[a].weight > T[b].weight;
}
void DFS(int root, int sum)
{
	path.push_back(root);
	if (sum > S)
	{
		path.pop_back();
		return; 
	}
	if (sum == S)
	{
		if (T[root].child.size() != 0)
		{
			path.pop_back();
			return;
		}
		for (int i = 0; i < path.size(); i++)
		{
			cout << T[path[i]].weight;
			if (i != path.size() - 1)
				cout << ' ';
			else
				cout << endl;
		}
		path.pop_back();
		return;
	}
	for (int i = 0; i < T[root].child.size(); i++)
	{
		DFS(T[root].child[i], sum + T[T[root].child[i]].weight);
	}
	path.pop_back();
}


void solution()
{
	cin >> N >> M >> S;
	T.resize(N);
	for (int i = 0; i < N; i++)
		cin >> T[i].weight;
	for (int i = 0; i < M; i++)
	{
		cin >> ID >> K;
		T[ID].child.resize(K);
		for (int j = 0; j < K; j++)
			cin >> T[ID].child[j];
		sort(T[ID].child.begin(), T[ID].child.end(), cmp);
	}
	DFS(0, T[0].weight);
	return;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}