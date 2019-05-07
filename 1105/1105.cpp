#include<iostream>
#include<math.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int N, num[10001];
int M[400][400], a, b, temp, cnt = 0, model = 0;

bool cmp(int a, int b)
{
	return a > b;
}

int f()
{
	int i = sqrt((double)N);
	while (i>=1)
	{
		if (N%i == 0)
			return i;
		i--;
	}
	return 1;
}

void insert(int x1, int x2, int y1, int y2)
{
	while (cnt!= N)
	{
		if (model % 4 == 0)
		{
			for (int i = x1; i < x2; i++)
				M[y1][i] = num[cnt++];
			model++;
			y1++;
		}
		else if (model % 4 == 1)
		{
			for (int i = y1; i < y2; i++)
				M[i][x2-1] = num[cnt++];
			model++;
			x2--;
		}
		else if (model%4==2)
		{
			for (int i = x2-1; i >= x1; i--)
				M[y2-1][i] = num[cnt++];
			model++;
			y2--; 
		}
		else if (model % 4 == 3)
		{
			for (int i = y2-1; i >= y1; i--)
				M[i][x1] = num[cnt++];
			model++;
			x1++;
		}
	}
}

void solution()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	sort(num, num + N, cmp);
	a = b = sqrt(N); temp = N;
	b = f(); a = N / b;
	insert(0, b, 0, a);
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << M[i][j];
			if (j != b - 1)
				cout << ' ';
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