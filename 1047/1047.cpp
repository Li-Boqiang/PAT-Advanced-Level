#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>			//For strcmp function
#pragma warning(disable:4996)
using namespace std;

char Student[40001][5];
vector<int> Course[2501];

bool comp(int a, int b)
{
	return strcmp(Student[a], Student[b]) < 0;
}


void solution()
{
	int  N, K;
	scanf("%d %d", &N, &K);
	int NumOfCourse, CourseID;
	for (int i = 0; i < N; i++)
	{
		scanf("%s %d", Student[i], &NumOfCourse);
		for (int j = 0; j < NumOfCourse; j++)
		{
			scanf("%d", &CourseID);
			Course[CourseID].push_back(i);
		}
	}
	for (int i = 1; i <= K; i++)
	{
		printf("%d %d\n", i, Course[i].size());
		sort(Course[i].begin(), Course[i].end(),comp);
		for (int j = 0; j < Course[i].size(); j++)
		{
			printf("%s\n", Student[Course[i][j]]);
		}
	}

}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
