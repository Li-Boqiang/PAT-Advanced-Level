#include<iostream>
#include<algorithm>
#include<math.h>
#pragma warning(disable:4996)
using namespace std;

int N;
int num[101], num_sort[101];

void adjust(int low, int high)
{
	int i = 1, j = 2;
	while (j<=high)
	{
		if (j + 1 <= high&&num_sort[j] < num_sort[j + 1])
			j++;
		if (num_sort[i] < num_sort[j])
		{
			swap(num_sort[i], num_sort[j]);
			i = j; j = i * 2;
		}
		else
			break;
	}
}
void solution()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> num_sort[i];
	}
	bool isInsert = true;
	int temp = num_sort[1];
	int range;
	for (int i = 2; i <= N; i++)
	{
		if (temp > num_sort[i])
		{
			range = i;
			for (; i < N; i++)
			{
				if (num[i] != num_sort[i])
				{
					isInsert = false;
					break;
				}
			}
		}
		if (i<N)
			temp = num_sort[i];
		if (isInsert == false)
			break;
	}
	if (isInsert)
	{
		cout << "Insertion Sort" << endl;
		sort(num+1, num + range + 1);
		for (int i = 1; i <= N; i++)
		{
			cout << num[i];
			if (i != N)
				cout << ' ';
		}
	}
	else
	{
		cout << "Heap Sort" << endl;
		int temp = N;
		while (temp >= 2 && num_sort[temp] > num_sort[temp - 1])
			temp--;
		swap(num_sort[1], num_sort[temp]);
		adjust(1, temp - 1);
		for (int i = 1; i <= N; i++)
		{
			cout << num_sort[i];
			if (i != N)
				cout << ' ';
		}
	}
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
