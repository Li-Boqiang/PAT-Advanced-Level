#include<iostream>
//#pragma warning(disable:4996)
using namespace std;
 
int coins[10010] = {0};
int N, M;
void solution()
{
    int i = 0;
    for (i = 0; i < M; i++)
    {
        if (coins[i]&&coins[M-i])       //如果恰好有这两枚硬币
        {
            if (i!=M-i)
                break;
            else if (coins[i]>=2)
                break;
        }
    }
    if (i == M)
        cout << "No Solution";
    else
        cout << i << ' ' << M - i;
    return;
}
 
int main()
{
    //freopen("2.txt", "r", stdin);
    cin >> N >> M;
    int value;
    for (int i = 0; i < N; i++)
    {
        cin >> value;
        coins[value]++;
    }
    solution();
    //system("pause");
    return 0;
}