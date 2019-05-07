#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include <cctype>
#pragma warning(disable:4996)
using namespace std;
typedef struct 
{
	int Ns;
	double TWS;
}info;
int N;
map<string, info> M;
string ID, school;
int score;
typedef struct 
{
	int rank;
	string ID;
	int TWS;
	int Ns;
}node;
vector<node> v;

bool cmp(node a, node b)
{
	if (a.TWS != b.TWS)
		return a.TWS > b.TWS;
	else if (a.Ns != b.Ns)
		return a.Ns < b.Ns;
	else
		return a.ID < b.ID;
}

void solution()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> ID >> score >> school;
		transform(school.begin(), school.end(),school.begin(), ::tolower);
		M[school].Ns++;
		if (ID[0] == 'B')
			M[school].TWS += score / 1.5;
		else if (ID[0] == 'A')
			M[school].TWS += score;
		else
			M[school].TWS += score*1.5;
	}
	cout << M.size() << endl;
	for (auto i = M.begin(); i != M.end(); i++)
		v.push_back({ 0, i->first ,(int)i->second.TWS,i->second.Ns });

	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
		v[i].rank = i + 1;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i].TWS == v[i - 1].TWS)
			v[i].rank = v[i - 1].rank;
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i].rank << ' ' << v[i].ID << ' ' << v[i].TWS << ' ' << v[i].Ns << endl;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}