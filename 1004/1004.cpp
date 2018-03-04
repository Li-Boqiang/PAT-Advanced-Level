//练习使用vector和map的一些用法
//这个题的坑在于，给出节点的child信息的时候，不是按顺序给出的，即有可能从下往上给出节点信息
//虽然这个题目给出的是一个树，但是这棵树是可以看做一个单源点有向图的，对于这个图的遍历是可以用BFS和DFS
//现在使用BFS广度优先遍历


//每个节点情况：有ID号，有child信息，可以使用map<int,vector<int>>来存储，第一个存储ID信息，第二个vector存储child情况
//BFD广度优先遍历的时候，需要借助队列queue，顺带练习使用队列了。

#include<iostream>
#include<vector>
#include<map>

#pragma warning(disable:4996)

using namespace std;

map<int, vector<int>> trees;						//map图的本质是一个红黑树，这里用map来存储这个树，，ID与child的关系，可应用map<int,vector<int>>
vector<int> res;									//res向量中存放的是非叶结点的信息

void solution()
{
	freopen("3.txt", "r", stdin);
	int n, m;										//n是节点总数，m是非叶结点的数量
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int id, k, son;
		cin >> id >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> son;
			trees[id].push_back(son);				//这里是输入child的信息
		}
	}
	//现在已经输入完所有的ID与其孩子的信息了，注意，这里的输入顺序并非按照从根节点开始的顺序。
	
	//BFS算法
	//res.push_back(0);								//初始化，第一层先把非叶结点设为0
	vector<int> now, next = {1};					//设置两个队列，一个是接下来要访问的层次，一个是现在正在访问的层次
	int floor = 0;									//起始是第0层，保存层次信息	
	while (!next.empty())							//若队列非空，则一直遍历
	{
		res.push_back(0);							//新的一层
		now = next;
		next.clear();
		for (auto i = now.begin(); i < now.end(); i++)
		{
			if (!trees[*i].empty())
				for (vector<int>::iterator j = trees[*i].begin(); j < trees[*i].end(); j++)
					next.push_back(*j);
			else
				res[floor]++;
		}
		floor++;
	}



	//输出结果
	cout << res[0];
	//int k = res.size();
	for (int i = 1; i < res.size(); i++)
	{
		cout <<' '<<res[i];
	}


}


int main()
{
	solution();
	system("pause");
	return 0;
}