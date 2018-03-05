#include<iostream>
#pragma warning(disable:4996)

using namespace std;

int k = 0;
int num[10001] = { 0 };
int flag = 0;
int temp = 0, sum = 0;						//temp表示临时和，sum表示当前已知的最大和
int tempstart = 0;
int start = 0, over = 0;								//start表示最大和子序列的开始，end表示结束
int solution()
{
	//int *num = (int *)malloc(10001 * sizeof(int));
	freopen("11.txt", "r", stdin);
	cin >> k;
	for (int i = 0; i < k; i++)				//输入这K个数，如果有正数，那么把标记为置为1
	{
		cin >> num[i];
		if (num[i]>=0)
		{
			flag = 1;
		}
	}
	if (!flag)
	{
		cout << "0 " << num[0] << ' ' << num[k - 1];
		return 0;
	}
	
	for (int i = 0; i < k; i++)				//这里是至少有一个正数的
	{
		temp += num[i];
		
		if (temp < 0)
		{
			temp = 0;
			tempstart = i + 1;				//如果当前和小于0了，置为0，并且从下一个开始
			continue;
		}
		if (temp > sum)
		{
			start = num[tempstart];
			over = num[i];
			sum = temp;
		}


	}

	cout << sum << ' ' << start << ' ' << over;
	return 0;
}

int main()
{
	solution();
	system("pause");
	return 0;
}