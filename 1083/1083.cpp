#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
typedef struct 
{
	string name;
	string ID;
	int g;
}student;
vector<student> s;
int N;
bool cmp(student a, student b)
{
	return a.g > b.g;
}
void solution()
{
	cin >> N;
	s.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> s[i].name >> s[i].ID >> s[i].g;
	}
	sort(s.begin(), s.end(), cmp);
	int grade1, grade2;
	cin >> grade1 >> grade2;
	bool flag = false;
	for (auto i = s.begin(); i != s.end(); i++)
	{
		if (i->g>=grade1&&i->g<=grade2)
		{
			cout << i->name << ' ' << i->ID << endl;
			flag = true;
		}
	}
	if (!flag)
	{
		cout << "NONE";
	}
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}