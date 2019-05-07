#include<iostream>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;

char num[50],s[50];
int N, cnt = 0;
double numSum = 0.0, temp;
void solution()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%s", num);
		sscanf(num, "%lf", &temp);			//temp用于计算求和
		sprintf(s, "%.2lf", temp);			//s字符串用于比较，这样比较起来比较方便
		bool flag = false;
		for (int j = 0; j < strlen(num); j++)
		{
			if (num[j] != s[j])
				flag = true;
		}
		if (flag || temp < -1000 || temp>1000)
		{
			printf("ERROR: %s is not a legal number\n", num);
			continue;
		}
		else
		{
			numSum += temp;
			cnt++;
		}
	}
	if (cnt == 1) {
		printf("The average of 1 number is %.2lf", numSum);
	}
	else if (cnt > 1) {
		printf("The average of %d numbers is %.2lf", cnt, numSum / cnt);
	}
	else {
		printf("The average of 0 numbers is Undefined");
	}

}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}