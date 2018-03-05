#include<iostream>
#include<vector>
#pragma warning(disable:4996)

using namespace std;
int N, M;                        //N is the total number of diamonds on the chain
								 //M isthe amount that the customer has to pay
int Chain[100010];
bool Find = false;
vector<int>SumFront;
vector<int> Min;            //用于存储最接近的
int temp;
int Over = 0x7FFFFFFF;

void solution()
{
	cin >> N >> M;
	SumFront.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &Chain[i]);
		//cin >> Chain[i];
		SumFront[i] = Chain[i];
		SumFront[i] += SumFront[i - 1];
	}
	int mid;
	for (int i = 1; i <= N; i++)
	{
		int right = N;
		int left = i;
		while (left<right)
		{
			mid = (right + left) / 2;
			if (SumFront[mid] - SumFront[i - 1] >= M)
				right = mid;
			else
				left = mid + 1;
		}
		temp = SumFront[right] - SumFront[i - 1] - M;

		if (Over>temp&&temp >= 0)
		{
			Min.clear();
			Over = temp;
			Min.push_back(i);
			Min.push_back(right);
		}
		else if (Over == temp)
		{
			Min.push_back(i);
			Min.push_back(right);
		}
	}

	for (vector<int>::iterator i = Min.begin(); i != Min.end(); i++)
	{
		printf("%d-", *i);
		//cout << *i << '-';
		i++;
		printf("%d\n", *i);
		//cout << *i << endl;
	}

}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
