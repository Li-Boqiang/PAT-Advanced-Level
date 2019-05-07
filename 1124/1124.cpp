#include<iostream>
#include<string>
#include<vector>
#include<map>
#pragma warning(disable:4996)
using namespace std;

int M, N, S;
map<string, bool>visit;
vector<string>v;
void solution()
{
	cin >> M >> N >> S;
	v.resize(M);
	for (int i = 0; i < M; i++)
		cin >> v[i];
	int temp = 0;
	bool flag = false;
	for (int i = 0; i*N+S-1+temp < M; i++)
	{
		while (visit.count(v[i*N + S - 1 + temp]) && (i*N + S - 1 + temp < M))
			temp++;
		cout << v[i*N + S - 1+temp] << endl;
		visit[v[i*N + S - 1 + temp]] = true;
		flag = true;

	}
	if (flag == false)
		cout << "Keep going...";
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}