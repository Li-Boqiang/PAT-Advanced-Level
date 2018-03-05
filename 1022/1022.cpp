//对于string类，使用getline(cin,str)来获得一行带空格的字符串，遇到换行符表示结束，将换行符丢弃你
//getline(cin, temp_keyword);
//istringstream is(temp_keyword);
//while (is >> temp_input)
//Book[i].KeyWords.push_back(temp_input);
//表示把一行字符串读入流中，然后把一个一个单词从流中依次读取到字符串，遇到空格表示结束
//这个用法需要包含头文件sstream
//ID这个数字的开头可能是0，比如0111111这样的ID，所以ID要用string类存储
//cin之后还要用getchar吸收一个换行符
//数量不大，可以直接搜索
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int Output[10001];

struct BookNode
{
	//int ID;												//防止出现00111111这样的ID
	string ID;
	string Title;
	string Author;
	vector<string> KeyWords;
	string Publisher;
	string Year;
}Book[10001];

bool comp(BookNode a, BookNode b)
{
	return a.ID < b.ID;
}

void solution()
{
	int N, M;
	cin >> N; 
	string temp_keyword;
	string temp_input;
	getchar();
	for (int i = 0; i < N; i++)
	{
		cin >> Book[i].ID; getchar();						
		//getline(cin,Book[i].ID);									//这样也可以
		getline(cin,Book[i].Title);
		getline(cin, Book[i].Author);
		getline(cin, temp_keyword);
		istringstream is(temp_keyword);
		while (is>>temp_input)
			Book[i].KeyWords.push_back(temp_input);
		getline(cin, Book[i].Publisher);
		getline(cin, Book[i].Year);
	}
	//输入完所有的信息
	sort(Book, Book + N, comp);				//排序

	cin >> M;
	getchar();
	bool FindBook = false;
	for (int i = 0; i < M; i++)
	{
		FindBook = false;
		getline(cin, temp_input);			//得到输入
		cout << temp_input << endl;
		int Num = temp_input[0] - '0';
		temp_input.erase(0, 3);
		switch (Num)
		{
		case 1:
		{
			for (int j = 0; j < N; j++)
			{
				if (Book[j].Title==temp_input)
				{
					FindBook = true;
					cout << Book[j].ID << endl;
				}
			}
			break;
		}
		case 2:
		{
			for (int j = 0; j < N; j++)
			{
				if (Book[j].Author == temp_input)
				{
					FindBook = true;
					cout << Book[j].ID << endl;
				}
			}
			break;
		}
		case 3:
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < Book[j].KeyWords.size(); k++)
				{
					if (Book[j].KeyWords[k]==temp_input)
					{
						FindBook = true;
						cout << Book[j].ID << endl;
					}
				}
			}
			break;
		}
		case 4:
		{
			for (int j = 0; j < N; j++)
			{
				if (Book[j].Publisher == temp_input)
				{
					FindBook = true;
					cout << Book[j].ID << endl;
				}
			}
			break;
		}
		case 5:
		{
			for (int j = 0; j < N; j++)
			{
				if (Book[j].Year == temp_input)
				{
					FindBook = true;
					cout << Book[j].ID << endl;
				}
			}
			break;
		}
		default:
			break;
		}
		if (!FindBook)
			cout << "Not Found" << endl;
	}
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
