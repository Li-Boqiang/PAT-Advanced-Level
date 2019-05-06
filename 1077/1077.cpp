#include<iostream>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int N;
string ans,s;

void solution()
{
	//cin >> N;
	//cin.ignore();          //用这两个或者下面的scanf
	scanf("%d\n", &N);

	for (int i = 0; i < N; i++)
	{
		getline(cin, s);
		int length = s.length();
		reverse(s.begin(), s.end());
		if (i == 0)
		{
			ans = s;
			continue;
		}
		else
		{
			int ans_length = ans.length();
			int min_length = min(ans_length, length);
			for (int j = 0; j < min_length; j++)
			{
				if (ans[j]!=s[j])
				{
					ans = ans.substr(0, j);
					break;
				}
			}
		}
	}
	reverse(ans.begin(), ans.end());
	if (ans.length() == 0)
		cout << "nai" << endl;
	else
		cout << ans << endl;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}