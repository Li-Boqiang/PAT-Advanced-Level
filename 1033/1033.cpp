#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
//#pragma warning(disable:4996)
using namespace std;
int Cmax, N;
double D, avg;
int sum, run;
typedef struct station
{
    double price;
    double distance;
}Station;
vector<Station> sta;
bool cmp(Station a, Station b)
{
    return a.distance < b.distance;
}
void solution()
{
    sort(sta.begin(), sta.end(), cmp);          //按从进到远进行排序
    //特殊情况
    if (sta[0].distance != 0)                  
    {
        cout << "The maximum travel distance = 0.00";
        return;
    }
    int location = 0;
    bool arrive = false;
    double cost = 0;
    double gas = 0;             //表示初始有多少油
    while (!arrive)
    {
        bool findcheap = false;
        double cheapest = sta[location].price;
        int next=-1;
        double minprice = 100000000;
        for (int i = location+1; i<N&&sta[i].distance<=sta[location].distance + Cmax*avg&&sta[i].distance<=D; i++)
        {
            if (sta[i].price < minprice)
            {
                next = i;
                minprice = sta[i].price;
                if (sta[i].price<cheapest)
                {
                    findcheap = true;
                    next = i;   //找到便宜的，跑到i这里
                    break;
                }
            }
        }
        if (findcheap)
        {
            cost += ((sta[next].distance - sta[location].distance) / avg-gas)*sta[location].price;
            gas = 0;
            location = next;
        }
        else if (next!=-1|| sta[location].distance + Cmax*avg >= D)//至少能到一个站，不至于没油
        {
            if (sta[location].distance+Cmax*avg>=D)//够了
            {
                arrive = true;
                cost += (D - sta[location].distance) / avg*sta[location].price;
                break;
            }
            //不够
            cost += (Cmax - gas)*sta[location].price;
            gas = Cmax - (sta[next].distance - sta[location].distance) / avg;
            location = next;
        }
        else
        {
            break;          //到不了
        }
    }
    if (arrive)
    {
        cout << fixed << setprecision(2) << cost;
    }
    else
    {
        cout << "The maximum travel distance = " << fixed << setprecision(2) << sta[location].distance + Cmax*avg;
    }
 
}
 
int main()
{
    //freopen("3.txt", "r", stdin);
    //Cmax表示油箱最大容量，D表示相距距离，avg表示平均每升油跑的距离，N表示加油站的数目
    cin >> Cmax >> D >> avg >> N;
    sta.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> sta[i].price >> sta[i].distance;
    }
    solution();
    //system("pause");
    return 0;
}