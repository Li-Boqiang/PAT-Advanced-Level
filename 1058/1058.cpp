#include<iostream>
#pragma warning(disable:4996)
using namespace std;
typedef struct
{
	int Sickle, Knut, Galleon;
}currency;

currency a, b, sum;
void solution()
{
	sum.Knut=a.Knut+b.Knut;
	sum.Sickle = sum.Knut / 29;
	sum.Knut = sum.Knut % 29;
	sum.Sickle = a.Sickle + b.Sickle + sum.Sickle;
	sum.Galleon = sum.Sickle / 17;
	sum.Sickle = sum.Sickle % 17;
	sum.Galleon = sum.Galleon + a.Galleon + b.Galleon;
	cout << sum.Galleon << '.' << sum.Sickle << '.' << sum.Knut;
	return;
}

int main()
{
	freopen("1.txt", "r", stdin);
	scanf("%d.%d.%d %d.%d.%d",&a.Galleon,&a.Sickle,&a.Knut,&b.Galleon,&b.Sickle,&b.Knut);
	solution();
	system("pause");
	return 0;
}