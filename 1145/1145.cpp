#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

bool isPrime(int x)
{
	if (x == 1)
		return false;
	for (int i = 2; i*i <= x; i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}
int MSize, N, M;
void solution()
{
	cin >> MSize >> N >> M;
	while (isPrime(MSize) == false)
		MSize++;
	int temp, k;
	vector<int>v(MSize);
	int j;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		
		for (j = 0; j < MSize; j++)
		{
			k = temp + j*j;
			if (v[k%MSize] == 0)
			{
				v[k%MSize] = temp;
				break;
			}
		}
		if(j==MSize)
			cout<< temp << " cannot be inserted." << endl;
	}
	int cnt = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		for ( j = 0;  j < MSize;  j++)
		{
			k = temp + j*j;
			if (v[k%MSize]==temp||v[k%MSize]==0)					//找到或者v[k]==0表示没找到
			{
				cnt = cnt + j + 1;
				break;
			}
		}
		if (j == MSize)
			cnt += j + 1;
	}
	printf("%.1f", 1.0*cnt / M);
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}