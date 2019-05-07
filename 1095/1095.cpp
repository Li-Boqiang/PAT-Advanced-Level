#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

typedef struct
{
	char ID[10];
	int time = 0, flag = 0;
}node;
int N, K, f;
vector<node> input, car;

bool cmp1(node a, node b)
{
	if (strcmp(a.ID, b.ID) != 0)
		return strcmp(a.ID, b.ID) < 0;
	else
		return a.time < b.time;
}
bool cmp2(node a, node b)
{
	return a.time < b.time;
}
void solution()
{
	cin >> N >> K;
	input.resize(N);
	int time2, h, m, s;
	char status[10];
	for (int i = 0; i < N; i++)
	{
		scanf("%s %d:%d:%d %s\n", input[i].ID, &h, &m, &s, &status);
		input[i].time = h * 3600 + m * 60 + s;
		if (strcmp(status, "in") == 0)
			input[i].flag = 1;
		else input[i].flag = -1;					//进进出出
	}
	sort(input.begin(), input.end(), cmp1);
	map<string, int> lasttime;
	int maxtime = 0;
	for (int i = 0; i < N - 1; i++)
	{
		if (strcmp(input[i].ID, input[i + 1].ID) == 0 && input[i].flag == 1 && input[i + 1].flag == -1)
		{
			car.push_back(input[i]); car.push_back(input[i + 1]);
			lasttime[input[i].ID] += (input[i + 1].time - input[i].time);
			if (maxtime < lasttime[input[i].ID])
				maxtime = lasttime[input[i].ID];
		}
	}
	sort(car.begin(), car.end(), cmp2);
	vector<int> carInSchool(N);
	for (int i = 0; i < car.size(); i++)
	{
		if (i == 0)
			carInSchool[i] += car[i].flag;
		else
			carInSchool[i] = carInSchool[i - 1] + car[i].flag;
	}
	int temp,j=0;
	for (int i = 0; i < K; i++)
	{
		scanf("%d:%d:%d", &h, &m, &s);
		time2 = h * 3600 + m * 60 + s;
		for (j=temp; j < car.size(); j++)
		{
			if (car[j].time > time2)
			{
				printf("%d\n", carInSchool[j - 1]);
				break;
			}
			else if (j == car.size() - 1)
				cout << carInSchool[j] << endl;					//最后一个了，有多少车就算多少辆车
		}
		temp = j;
	}
	for (auto i = lasttime.begin(); i != lasttime.end(); i++)
	{
		if (i->second == maxtime)
			cout << i->first << ' ';
	}
	printf("%02d:%02d:%02d", maxtime / 3600, (maxtime % 3600) / 60, maxtime % 60);
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	return 0;
}