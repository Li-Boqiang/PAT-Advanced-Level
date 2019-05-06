#include<iostream>
#include<vector>
#include<string>
#pragma warning(disable:4996)
using namespace std;

int n;
string temp;
vector<int>pre, mid,value;
bool flag = false;
void post(int root, int start, int end)
{
	if (start > end)
		return;
	int i = start;
	while (i<end&&mid[i]!=pre[root])
	{
		i++;
	}
	post(root + 1, start, i - 1);
	post(root + 1 + i - start, i + 1, end);
	if (flag)
	{
		cout << ' ';
	}
	cout << value[mid[i]];
	flag = true;
}

void solution()
{
	cin >> n;
	int num, top = 0;
	int stack[31] = {0};
	int c1 = 0;
	for (int i = 0; i < n*2; i++)
	{
		cin >> temp;
		if (temp=="Push")
		{
			cin >> num;
			value.push_back(num);
			pre.push_back(c1);
			stack[top++]=c1++;
		}
		else if (temp=="Pop")
		{
			mid.push_back(stack[--top]);
		}
	}
	post(0, 0, n - 1);
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}