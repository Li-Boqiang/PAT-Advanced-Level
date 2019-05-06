#include<iostream>
#include<string>
#pragma warning(disable:4996)
using namespace std;


int T;
long long int A, B, C, D;
void solution()
{
	cin >> T;
	bool res;
	for (int i = 0; i < T; i++)
	{
		cin >> A >> B >> C;
		D = A + B;
		if (A > 0 && B > 0 && D < 0)
			res = true;							//上溢一定大于
		else if (A < 0 && B < 0 && D>=0)
			res = false;						//下溢一定小于
		else
			res = (D > C);
		if (res)
			cout << "Case #" << i + 1 << ": " << "true" << endl;
		else
			cout << "Case #" << i + 1 << ": " << "false" << endl;
	}
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}