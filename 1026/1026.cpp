//要点1 在VIP来的时候，如果现在有专门为VIP使用的桌子，VIP是可以插队的
//要点2 如果VIP来的时候，没有VIP桌子可以使用，那么VIP就认为是普通用户
//要点3 没有VIP客户的时候，那么下一个来的人就直接使用可以用的桌子，不论这个桌子是不是VIP桌
//信息1 给出桌子的数量，VIP桌的数量和ID，给出客户来的时间和要求服务的时间，是否是VIP
//要点4 输出开始玩的时间精确到秒，但是在输出等待的的时间的时候是精确到分钟，四舍五入？
//要点5 要输出每个桌子接待顾客的数量
//要点6 给客户来临的时间的时候，顺序是乱序
//

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>							//包含sort函数
#pragma warning(disable:4996)
using namespace std;

typedef struct node
{
	string ArriveTime;						//到达时间
	int ArriveTime_Sec;						//换算成秒
	int GetServeTime;						//得到服务的时间
	int NeedTime;							//需要玩的时间
	int Property;							//属性值
}Player;

int N, K, M;								//n是顾客的总数，K是桌子的总数，M是VIP桌子

vector<Player> Ordinary;
vector<Player> Vip;

struct tab
{
	int NumOfServePlayer = 0;
	bool TableProperty = false;
	int ReleaseTime = 8 * 3600;
}Table[101];
bool cmp(Player a, Player b)
{
	return a.ArriveTime < b.ArriveTime;		//按从小到大排列，在sort函数的第三个参数中
}

void OutPut(Player a)						//输出函数
{
	cout << a.ArriveTime << ' ';
	cout << a.GetServeTime / 36000 << (a.GetServeTime % 36000) / 3600 << ":" << (a.GetServeTime % 3600) / 600 << (a.GetServeTime % 600) / 60 ;
	cout << ":" << (a.GetServeTime % 60) / 10 << a.GetServeTime % 10<<' ';
	cout << (a.GetServeTime - a.ArriveTime_Sec + 30) / 60<<endl;
}

void solution()
{
	cin >> N;
	Player temp;
	for (int i = 0; i < N; i++)	//输入所有的客户信息
	{
		cin >> temp.ArriveTime;
		cin >> temp.NeedTime;
		if (temp.NeedTime > 120)
			temp.NeedTime = 120;
		cin >> temp.Property;
		temp.ArriveTime_Sec = (temp.ArriveTime[0] - '0') * 36000 + (temp.ArriveTime[1] - '0') * 3600
							+ (temp.ArriveTime[3] - '0') * 600 + (temp.ArriveTime[4] - '0') * 60 
							+ (temp.ArriveTime[6] - '0') * 10 + (temp.ArriveTime[7] - '0');
		if (temp.Property==0)
			Ordinary.push_back(temp);
		else
			Vip.push_back(temp);
	}
	cin >> K >> M;
	int temp1;
	for (int i = 0; i < M; i++)		//得到哪些是VIP桌子
	{
		cin >> temp1;
		Table[temp1].TableProperty = true;
	}

	sort(Ordinary.begin(), Ordinary.end(), cmp);		//排序，从小到大
	sort(Vip.begin(), Vip.end(), cmp);
	
	int i = 0, j = 0;				//分别是服务VIP和普通客户的数量

	int OrdTime, VipTime;
	int MinTime = 21 * 3600;
	int flag = -1;
	while (i+j<Ordinary.size()+Vip.size())
	{
		MinTime = 21 * 3600;
		OrdTime = 21 * 3600;
		VipTime = 21 * 3600;


		for (int i1 = 1; i1 <= K; i1++)				//找到一个就近的能使用的桌子，小ID优限
		{
			if (Table[i1].ReleaseTime<MinTime)
			{
				MinTime = Table[i1].ReleaseTime;
				flag = i1;
			}
		}
		if (i<Ordinary.size())						//第一个普通顾客来
		{
			OrdTime = Ordinary[i].ArriveTime_Sec;
			if (OrdTime<MinTime)					//如果来早了
			{
				OrdTime = MinTime;					//等着
			}
		}
		if (j < Vip.size())
		{
			VipTime = Vip[j].ArriveTime_Sec;							//得到第一个VIP顾客的时间
			if (VipTime < MinTime)
			{
				VipTime = MinTime;									//如果来早了，等着
			}
		}

		bool ServeVip;
		if (OrdTime < VipTime&&OrdTime < 21 * 3600)
			ServeVip = false;
		else if (VipTime < OrdTime&&VipTime < 3600 * 21)
			ServeVip = true;
		else if (VipTime == OrdTime&&VipTime < 3600 * 21)
		{
			if (Table[flag].TableProperty || Vip[j].ArriveTime_Sec < Ordinary[i].ArriveTime_Sec)
				ServeVip = true;
			else
				ServeVip = false;
		}
		else if (OrdTime == 21 * 3600 && VipTime == 21 * 3600)
			break;

		if (ServeVip)
		{
			if (Table[flag].TableProperty==false)
			{
				for (int i1 = 1; i1 <= K; i1++)
				{
					if (Table[i1].TableProperty&&Table[i1].ReleaseTime==MinTime)
					{
						flag = i1;
					}
				}
			}

			Vip[j].GetServeTime = VipTime;
			Table[flag].ReleaseTime = VipTime + Vip[j].NeedTime * 60;
			OutPut(Vip[j]);
			Table[flag].NumOfServePlayer++;
			j++;
		}
		else
		{
			Ordinary[i].GetServeTime = OrdTime;
			Table[flag].ReleaseTime = OrdTime + Ordinary[i].NeedTime * 60;
			OutPut(Ordinary[i]);
			Table[flag].NumOfServePlayer++;
			i++;
		}
	}
	cout << Table[1].NumOfServePlayer;
	for (int i1 = 2; i1 <= K; i1++)
	{
		cout << ' ' << Table[i1].NumOfServePlayer;
	}
	
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}