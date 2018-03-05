//思路分析：
//1、需要将每个数都变成十进制，方便比较。
//2、给定的进制只能在（给的数的数码最大+1）~max(另一个数的值，数码最大)+1（必须加1，下面给出理由）中给出。  因为会出现这种情况，5 5 1 10，这种情况显然是6进制符合要求。
//3、使用二分法搜索
//4、pow函数的返回值是double，在longlongint 中，当数很大的时候，会丢失精度，所以还需要自己写一个乘方函数

#include<iostream>
#include<string>
#include<cmath>
#pragma warning(disable:4996)

using namespace std;
string n1, n2;
int tag, radix;
unsigned long long n1_10, n2_10;


unsigned long long tras(string n, unsigned long long rad)
{
	int num;								//表示位数
	unsigned long long res = 0;
	for (int i = 0; i < n.length(); i++)
	{
		if (n[i] <= 'z'&&n[i] >= 'a')			//如果这个数是a~z之间
			res = res*rad + (n[i] - 'a' + 10);
		else
			res = res*rad + (n[i] - '0');
	}
	return res;
}

unsigned long long getrad(string n)		//得到的是比字符串最大的数码还大1的数，即二分查找法的起点。
{
	int zuida = 0;
	for (int i = 0; i < n.length(); i++)
	{
		if (n[i] <= 'z'&&n[i] >= 'a')			//如果这个数是a~z之间
			zuida = zuida >(n[i] - 'a' + 10) ? zuida : (n[i] - 'a' + 10);
		else
			zuida = zuida > (n[i] - '0') ? zuida : (n[i] - '0');
	}
	return zuida+1;
}

void solution()
{
	
	cin >> n1 >> n2 >> tag >> radix;
	unsigned long long low, high, mid;
	//先求得n1或者n2的具体10进制值，最后结果的评判。n1==n2时，找到进制。否则没有
	//进制的最小值是n2数的最大数码+1，最大值是n1的十进制值，因为会给这种情况，10000000 10 1 10，
	if (tag == 2) { string temp = n1;  n1 = n2; n2 = temp; }

	n1_10 = tras(n1, radix);
	low = getrad(n2);
	high = (n1_10+1) > getrad(n2) ?  (n1_10+1) : getrad(n2);


	while (low<=high)
	{
		mid = (low + high) / 2;
		if (tras(n2, mid) > n1_10)
			high = mid - 1;
		else if (tras(n2, mid) < n1_10)
			low = mid + 1;
		else
		{
			cout << mid;
			return;
		}
	}

		cout << "Impossible";


}


int main()
{
	freopen("7.txt", "r", stdin);
	solution();

	system("pause");
	return 0;
}