#include<iostream>
#include<vector>
#pragma warning(disable:4996)
#define min(a,b)    (((a) < (b)) ? (a) : (b))
using namespace std;
int N;
vector<int>Distance;
int M;
void solution()
{
	cin >> N;
	Distance.resize(N+1);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &Distance[i]);
		Distance[i] += Distance[i - 1];
	}
	cin >> M;
	int Start, End,temp1,temp2;
	for (int i = 0; i < M; i++)
	{
		cin >> Start >> End;
		if (End<Start)
		{
			int temp = Start;
			Start = End;
			End = temp;
		}
		temp1 = Distance[End-1] - Distance[Start-1];
		temp2 = Distance[N] - Distance[End-1] + Distance[Start-1];
		cout << min(temp1, temp2) << endl;
	}
}
int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}