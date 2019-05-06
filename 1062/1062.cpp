#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

typedef struct
{
	int ID_Number;
	int Virtue_Grade;
	int Talent_Grade;
	int tag;			//0表示圣人，1表示君子，2表示愚人，3表示小人
}people;
vector<people> p;
int N, L, H;

bool cmp(people a, people b)
{
	if (a.tag != b.tag)
		return a.tag < b.tag;
	else if ((a.Virtue_Grade + a.Talent_Grade) != (b.Virtue_Grade + b.Talent_Grade))
		return (a.Virtue_Grade + a.Talent_Grade) > (b.Virtue_Grade + b.Talent_Grade);
	else if (a.Virtue_Grade != b.Virtue_Grade)
		return a.Virtue_Grade > b.Virtue_Grade;
	else
		return a.ID_Number < b.ID_Number;
}
void solution()
{
	people input;
	cin >> N >> L >> H;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &input.ID_Number, &input.Virtue_Grade, &input.Talent_Grade);
		//cin >> input.ID_Number >> input.Virtue_Grade >> input.Talent_Grade;
		if (input.Talent_Grade >= L&&input.Virtue_Grade >= L)
		{
			if (input.Talent_Grade >= H&&input.Virtue_Grade >= H)
				input.tag = 0;
			else if (input.Virtue_Grade >= H)
				input.tag = 1;
			else if (input.Virtue_Grade >= input.Talent_Grade)
				input.tag = 2;
			else
				input.tag = 3;
			p.push_back(input);
		}
	}
	sort(p.begin(), p.end(), cmp);
	cout << p.size() << endl;
	for (auto i = p.begin(); i != p.end(); i++)
		printf("%d %d %d\n", i->ID_Number, i->Virtue_Grade, i->Talent_Grade);
		//cout << i->ID_Number << ' ' << i->Virtue_Grade << ' ' << i->Talent_Grade << endl;
	return;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
