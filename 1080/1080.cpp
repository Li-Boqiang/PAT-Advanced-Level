#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

int N, M, K;
typedef struct 
{
	int Ge;
	int Gi;
	int Total;
	vector<int> wish;		//志愿集合
	int ID;
}student;
vector<student> S;			//	学生集合
int college[101];

bool cmp(student a, student b)			//排序函数
{
	if (a.Total != b.Total)
		return a.Total > b.Total;
	else 
		return a.Ge > b.Ge;
}

void solution()
{
	cin >> N >> M >> K;
	S.resize(N);
	int temp;
	for (int i = 0; i < M; i++)
	{
		cin >> college[i];		//输入名额数量
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d ", &S[i].Ge, &S[i].Gi);
		S[i].Total = S[i].Ge + S[i].Gi;
		S[i].wish.resize(K);
		for (int j = 0; j < K; j++)				//输入志愿信息
		{
			scanf("%d", &S[i].wish[j]);
		}
		S[i].ID = i;
	}
	vector<student> S1 = S;						//保存ID信息
	sort(S.begin(), S.end(), cmp);
	vector<vector<int>> res;			//存放结果
	res.resize(M);

	for (int i = 0; i < S.size(); i++)
	{
		for (int j = 0; j < K; j++)
		{
			temp = S[i].wish[j];		//当前志愿
			if (college[temp] > 0||(S1[res[temp].back()].Ge == S[i].Ge&&S1[res[temp].back()].Total == S[i].Total))		//还有名额，或者招满情况，比较报考学校最后一名学生的成绩和当前学生的成绩
			{
				res[temp].push_back(S[i].ID);		//投档
				college[temp]--;
				break;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		sort(res[i].begin(), res[i].end());
		for (int j = 0; j < res[i].size(); j++)
		{
			printf("%d", res[i][j]);
			if (j!= res[i].size()-1)
			{
				printf(" ");
			}
		}
		cout << endl;
	}
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}