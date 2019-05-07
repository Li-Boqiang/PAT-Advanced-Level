#include<iostream>
using namespace std;
int temp, N, cnt = 0;
bool num[100002] = { 0 };
int main(){
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		/*只保存在[0,N]区间的数*/
		if (temp > N || temp <= 0)
			continue;
		num[temp] = true;
	}
	while (++cnt){
		if (num[cnt] == false)break;
	}
	cout << cnt;
	return 0;
}