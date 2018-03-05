#include<iostream>
#include<algorithm>
#include<string>
#pragma warning(disable:4996)
using namespace std;
struct Stu
{
	int id;
	int score[3];
	float aver;
	int rank[4];
	int best;
} student[2001];

int course = 0;
int x,y;
int c, m, e;
float a;
bool exist[1000000] = { 0 };

bool comp(Stu a, Stu b)
{
	return a.score[course-1] > b.score[course-1];
}
bool comp_aver(Stu a, Stu b)
{
	return a.aver > b.aver;
}

void solution()
{
	cin >> x >> y;
	for (int i = 0; i < x; i++)
	{
		cin >> student[i].id;
		exist[student[i].id] = true;
		//for (int j = 0; j < 3; j++)
		cin >> student[i].score[0] >> student[i].score[1] >> student[i].score[2];
		student[i].aver = (student[i].score[0] + student[i].score[1] + student[i].score[2]) / 3.0;
	}
	//输入完毕

	sort(student, student + x, comp_aver);	//按照均分paiming
	//student[0].best = 1;
	student[0].rank[0] = 1;
	for (int i = 1; i < x; i++)
	{
		student[i].rank[0] = i + 1;
		if (student[i].aver==student[i-1].aver)
		{
			student[i].rank[0] = student[i - 1].rank[0];
		}
	}
	

	for (course = 1; course < 4; course++)
	{
		sort(student, student + x, comp);
		student[0].rank[course] = 1;
		for (int i = 1; i < x; i++)
		{
			student[i].rank[course] = i + 1;
			if (student[i].score[course-1]==student[i-1].score[course-1])
			{
				student[i].rank[course] = student[i - 1].rank[course];
			}
		}
	}
	//确定最终排名
	for (int i = 0; i < x; i++)
	{
		int minn = student[i].rank[3];
		student[i].best = 3;
		for (int j = 2; j >= 0; j--)
		{
			if (student[i].rank[j]<=minn)
			{
				minn = student[i].rank[j];
				student[i].best = j;
			}
		}
	}

	string str = "ACME";
	for (int i = 0; i < y; i++)
	{
		int temp;
		cin >> temp;
		if (exist[temp])
		{
			for (int j = 0; j < x; j++)
			{
				if (student[j].id == temp)
				{
					cout << student[j].rank[student[j].best] << ' ' << str[student[j].best]<<endl;
				}
			}
		}
		else
			cout << "N/A"<<endl;
		
	}


}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}