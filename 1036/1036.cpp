#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
typedef struct student
{
	string name;
	char gender;
	string ID;
	int score;
}Student;
vector<Student> male, female;
int N;
bool cmp(Student a, Student b)
{
	if (a.gender == 'M')
		return a.score < b.score;
	else
		return a.score > b.score;
}
void solution()
{
	sort(male.begin(),male.end(),cmp);
	sort(female.begin(), female.end(), cmp);
	if (female.size())
		cout << female[0].name << ' ' << female[0].ID << endl;
	else
		cout << "Absent" << endl;
	if(male.size())
		cout << male[0].name << ' ' << male[0].ID << endl;
	else
		cout << "Absent" << endl;
	if (female.size() && male.size())
		cout << female[0].score - male[0].score;
	else
		cout << "NA";
}

int main()
{
	freopen("2.txt", "r", stdin);
	Student input;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> input.name >> input.gender >> input.ID >> input.score;
		if (input.gender == 'M')
			male.push_back(input);
		else
			female.push_back(input);
	}
	solution();
	system("pause");
	return 0;
}
