#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#pragma warning(disable:4996)

using namespace std;

 vector<int> Student[26*26*26*10+1];	//记录选了那些课

int NumOfStudent, NumOfCourse;

string temp;

void solution()
{
	cin >> NumOfStudent >> NumOfCourse;
	int CourseID;						//课程号
	int RigisteredStudent;				//选这门课的学生数
	int StudentID;
	char StudentName[5];
	for (int i = 0; i < NumOfCourse; i++)//输入所有选课学生的信息
	{
		cin >> CourseID;
		cin >> RigisteredStudent;
		for (int j = 0; j < RigisteredStudent; j++)
		{
			scanf("%s", &StudentName);				//注意不能用cin，否则会超时
			StudentName[4] = ' ';
			StudentID = (StudentName[0] - 'A') * 26 * 26 * 10 + (StudentName[1] - 'A') * 26 * 10 + (StudentName[2] - 'A') * 10 + (StudentName[3] - '0');
			Student[StudentID].push_back(CourseID);
		}

	}

	for (int i = 0; i < NumOfStudent; i++)
	{
		scanf("%s", &StudentName);					//注意不能用cin，否则会超时
		StudentID = (StudentName[0] - 'A') * 26 * 26 * 10 + (StudentName[1] - 'A') * 26 * 10 + (StudentName[2] - 'A') * 10 + (StudentName[3] - '0');
		sort(Student[StudentID].begin(), Student[StudentID].end());
		printf("%s", StudentName);					//注意不能用cin，否则会超时
		cout <<  ' ' << Student[StudentID].size();
		for (int j = 0; j < Student[StudentID].size(); j++)
		{
			cout <<' '<< Student[StudentID][j];
		}
		cout << endl;
	}

}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}