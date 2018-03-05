//1、人数超过2人，即至少是3个人才能被定义是一个团伙
//2、输出这个团伙的头目
//每个人的姓名都是由3个大写字母（A~Z）组成
//26*26*26这个数字太大，需要把这最多1000个人按名字顺序排好，然后分配ID号
//于是想到用map
//注意，给的是最多1000通电话，于是数组最少要开到2000，因为一通电话两个人，也就是最多2000个人
#include<iostream>
#include<string>
#include<map>
#pragma warning(disable:4996)

using namespace std;
map<string, int> String2int;				//用于转换
map<int, string> Int2string;
map<string, int>Answer;
int ID = 1;									//ID顺便也保存了有多少人
int Weight[2010];
int N, K;
int Call[2010][2010];						//存储电话时长矩阵
bool visit[2010] = { false };
int head, NumOfMenber=0;
int TotalWeight = 0;
void DFS(int u)
{
	visit[u] = true;
	NumOfMenber++;
	if (Weight[u]>Weight[head])
	{
		head = u;
	}
	for (int i = 1; i < ID; i++)
	{
		if (Call[u][i]>0)
		{
			TotalWeight += Call[u][i];
			Call[u][i] = Call[i][u] = 0;
			if (!visit[i])
				DFS(i);
		}
	}

}

int tras(string s)							//将字符串转为ID号
{
	if (String2int[s]==0)
	{
		String2int[s] = ID;
		Int2string[ID] = s;
		return ID++;
	}
	else
		return String2int[s];
}

void DFSSearch()
{
	for (int i = 1; i < ID; i++)
	{
		if (!visit[i])
		{
			head = i;NumOfMenber = 0;TotalWeight = 0;
			DFS(i);
			if (NumOfMenber>2&&TotalWeight>K)
				Answer[Int2string[head]] = NumOfMenber;
		}
	}
}




void solution()
{
	int w;
	int ID1, ID2;
	cin>>N>>K;
	fill(Call[0], Call[0] + 1001 * 1001, 0);
	for (int i = 0; i < N; i++)
	{
		string a_name, b_name;
		cin >> a_name >> b_name >> w;
		ID1 = tras(a_name);
		ID2 = tras(b_name);
		Call[ID1][ID2] += w; Call[ID2][ID1] += w; Weight[ID1] += w; Weight[ID2] += w;			//注意要全用+=，防止AAA BBB 10  AAA BBB 20这样的记录
	}
	//输入完所有数据，并把每个用户的权重保存了下来
	DFSSearch();
	cout << Answer.size() << endl;
	for (map<string,int>::iterator i = Answer.begin(); i != Answer.end(); i++)
	{
		cout << i->first <<' '<< i->second << endl;
	}
}




int main()
{
	freopen("4.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}