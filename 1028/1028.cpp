#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;

typedef struct student
{
	int ID;
	char name[10];
	int score;
}Student;

vector<Student> stu;
int n, c;
bool cmp1(Student a, Student b)
{
	return a.ID<b.ID;		//ID递增排序
}
bool cmp2(Student a, Student b)
{
	int temp = strcmp(a.name, b.name);
	if (temp)
		return temp <= 0;
	else
		return a.ID<b.ID;
}
bool cmp3(Student a, Student b)
{
	if (a.score != b.score)
		return a.score < b.score;
	else
		return a.ID<b.ID;
}
void solution()
{
	cin >> n >> c;
	stu.resize(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %s %d", &stu[i].ID, stu[i].name, &stu[i].score);
	}
	switch (c)
	{
	case 1:
		sort(stu.begin(), stu.end(), cmp1);
		break;
	case 2:
		sort(stu.begin(), stu.end(), cmp2);
		break;
	case 3:
		sort(stu.begin(), stu.end(), cmp3);
		break;
	default:
		break;
	}
	for (auto i = stu.begin(); i != stu.end(); i++)
	{
		printf("%06d %s %d\n", i->ID, i->name, i->score);
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}