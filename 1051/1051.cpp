//算法是，先把要验证的序列输入进数组中，然后按照顺序1~n把数字进栈
//每进入一个数字，判断1：有没有超出最大范围，超出了就break。
//如果没超过，就从数组的第一个数字开始判断，看看是否与栈顶元素相等，
//while相等，就一直弹出栈，如果不相等就继续按顺序把数字压入栈
//最后根据变量flag的值输出yes或者no
#include<iostream>
#include<stack>
#pragma warning(disable:4996)

using namespace std;
int N, M, K;//M,堆栈的最大容量，N序列的长度，K要检查的弹出序列的数量
void solution()
{
	cin >> M >> N >> K;
	int num[1001];
	for (int i = 0; i < K; i++)
	{
		bool flag = 0;
		int suit = 0;
		stack<int> Stack;
		for (int x = 0; x < N; x++)
		{
			cin >> num[x];
		}

		for (int j = 1; j <= N; j++)
		{
			Stack.push(j);
			if (Stack.size()>M)
				break;
			while (!Stack.empty()&&Stack.top()==num[suit])
			{
				Stack.pop();
				suit++;
			}
		}
		if (suit == N)
			flag = true;
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}