#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#pragma warning(disable:4996)
using namespace std;

typedef struct student
{
	//long long int num;	//不知道哪里不对，如果用 long long int 则测试点3会答案错误，但是在牛客网上是全对的
	string num;
	int local_rank;
	int score;
	int final_rank;
	int location;
}Student;
vector<Student> stu;
int N, M;

bool cmp(const Student &a, const Student &b)
{
	if (a.score != b.score)
		return a.score > b.score;
	else
		return a.num < b.num;
}

void solution()
{
	//int input_num;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> M;
		int length = stu.size();//保存上一次的大小
		int new_length = length + M;
		stu.resize(length + M);
		for (int j = length; j < new_length; j++)
		{
			cin >> stu[j].num;
			cin >> stu[j].score;
			stu[j].location = i + 1;
		}
		sort(stu.begin() + length, stu.end(), cmp);
		stu[length].local_rank = 1;
		for (int j = length + 1; j < new_length; j++)
		{
			if (stu[j - 1].score == stu[j].score)
				stu[j].local_rank = stu[j - 1].local_rank;
			else
				stu[j].local_rank = j - length + 1;
		}

	}
	sort(stu.begin(), stu.end(), cmp);
	stu[0].final_rank = 1;
	for (int i = 1; i < stu.size(); i++)
	{
		if (stu[i - 1].score == stu[i].score)
			stu[i].final_rank = stu[i - 1].final_rank;
		else
			stu[i].final_rank = i + 1;
	}
	cout << stu.size() << endl;
	for (int i = 0; i < stu.size(); i++)
	{
		cout << stu[i].num << ' ' << stu[i].final_rank << ' ' << stu[i].location << ' ' << stu[i].local_rank << endl;
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}