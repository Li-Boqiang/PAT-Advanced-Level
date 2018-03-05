#include<iostream>
#include<string>
#pragma warning(disable:4996)
using namespace std;

string Card[55];
char c[6]= { "SHCDJ" };
void solution()
{
	for (int i = 0; i < 54; i++)
	{
		Card[i] += c[i/13];
		Card[i]+=to_string(i%13+1);
	}
	//Input how to shuffle
	int Trans,Shuffle[55];
	cin >> Trans;
	for (int i = 0; i < 54; i++)
		cin >> Shuffle[i];

	string temp[55];
	for (int i = 0; i < Trans; i++)
	{
		for (int i = 0; i < 54; i++)
		{
			temp[Shuffle[i]-1] = Card[i];
		}
		for (int i = 0; i < 54; i++)
		{
			Card[i]=temp[i];
		}
	}

	//Output
	for (int i = 0; i < 53; i++)
	{
		cout << Card[i] << ' ';
	}
	cout << Card[53];
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}