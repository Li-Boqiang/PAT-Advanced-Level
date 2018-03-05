#include<iostream>
#include<string>
#include<functional>
#include<set>	
#include<stack>
#pragma warning(disable:4996)

using namespace std;

stack<int> Stk;
multiset<int>ups;
multiset<int, greater<int>> lows;
int N;
bool comp(int a, int b)
{
	return a < b;
}

void solution()
{
	cin >> N;
	char str[20];						//用于接收命令
	int mid=0;						//用于记录中位数
	int Number;
	for (int i = 0; i < N; i++)	
	{
		scanf("%s", &str);
		switch (str[1])
		{
		case ('u')	:			//Push
			scanf("%d", &Number);
			//cin >> Number;
			Stk.push(Number);
			if (Number > mid)
				ups.insert(Number);
			else
				lows.insert(Number);
			if (ups.size() > lows.size())
			{
				lows.insert(*ups.begin());
				ups.erase(ups.begin());
			}
			else if (lows.size()>ups.size()+1)
			{
				ups.insert(*lows.begin());
				lows.erase(lows.begin());
			}
			mid = *lows.begin();
			break;
		case('o'):									//POP
			if (Stk.empty())
				printf("Invalid\n");
				//cout << "Invalid" << endl;
			else
			{
				int t = Stk.top();
				Stk.pop();
				printf("%d\n",t);
				//cout << t << endl;
				if (t > *lows.begin())
					ups.erase(ups.find(t));
				else
					lows.erase(lows.find(t));
				//调整
				if (Stk.empty())					//取出后为空，则mid=0，重置
					mid = 0;
				else
				{
					if (ups.size() > lows.size())
					{
						lows.insert(*ups.begin());
						ups.erase(ups.begin());
					}
					else if (lows.size() > ups.size() + 1)
					{
						ups.insert(*lows.begin());
						lows.erase(lows.begin());
					}
					mid = *lows.begin();

				}
			}
			break;
		case('e'):
			if (Stk.empty())
				printf("Invalid\n");
				//cout << "Invalid" << endl;
			else
				printf("%d\n",mid);
				//cout << mid << endl;
			break;
		default:
			break;
		}
		
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;

}