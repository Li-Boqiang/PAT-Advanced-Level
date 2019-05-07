#include<iostream>
#include<algorithm>
#include<math.h>
#pragma warning(disable:4996)
using namespace std;

int N;
int num[101], num_sort[101];
void solution()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> num_sort[i];
	}
	bool isInsert = true;
	int temp = num_sort[0];
	int range;
	for (int i = 1; i < N; i++)
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
		if(i<N)
			temp = num_sort[i];
		if (isInsert == false)
			break;
	}
	if (isInsert)
	{
		cout << "Insertion Sort" << endl;
		sort(num, num + range + 1);
	}
	else
	{
		cout << "Merge Sort" << endl;
		int range = 1;
		//通过模拟来进行归并排序
		bool flag = true;						//用于标记是否达到当前状态
		while (flag)
		{
			flag = false;
			for (int i = 0; i < N; i++)
			{
				if (num[i] != num_sort[i]) 
				{
					flag = true;
					break;
				}
			}
		range *= 2;
		for (int i = 0; i < N/range; i++)
		{
			sort(num + i*range, num + (i + 1)*range);
		}
		sort(num + N / range*range, num + N);
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << num[i];
		if (i != N-1)
			cout << ' ';
	}
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}