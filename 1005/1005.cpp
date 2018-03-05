#include<iostream>
#include<string>
using namespace std;

void output(int a)
{
	int b = a;
	switch (b)
	{
	case 0:
		cout << "zero";
		break;
	case 1:
		cout << "one";
		break;
	case 2:
		cout << "two";
		break;
	case 3:
		cout << "three";
		break;
	case 4:
		cout << "four";
		break;
	case 5:
		cout << "five";
		break;
	case 6:
		cout << "six";
		break;
	case 7:
		cout << "seven";
		break;
	case 8:
		cout << "eight";
		break;
	case 9:
		cout << "nine";
		break;
	default:
		break;
	}
}

void solution()
{
	string str;
	cin >> str;
	int res = 0;

	for (int i = 0; i < str.length(); i++)
	{
		res += (str[i] - '0');
	}

	if (res>99)
	{
		output(res / 100);
		cout << ' ';
		output((res - res / 100 * 100) / 10);
		cout << ' ';
		output(res - res / 10 * 10);
	}
	else if (res > 9)
	{
		output(res / 10);
		cout << ' ';
		output(res % 10);
	}
	else
	{
		output(res);
	}


}


int main()
{
	solution();
	system("pause");
	return 0;

}