#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int value[50][50]; //각 이닝의 선수 결과
int visit[9]; //선수 선택여부
vector<int> v;
int maxScore;

void solve(vector<int> order) {
	int tmp = 0; //득점
	int cur = 0; //몇번째 선수
	for (int i = 0; i < N; i++){	
		int out = 0;  //아웃
		int one = 0; int two = 0; int three = 0; //1루,2루,3루
		while (out<3) {
			cur %= 9; //현재 타자
			int result = value[i][order[cur]]; //현재 선수 결과
			if (result == 0) out++; 
			else if (result == 1) { 
				tmp += three;
				three = two;
				two = one;
				one = 1;
			}
			else if (result == 2) {
				tmp += (three + two);
				three = one;
				two = 1;
				one = 0;
			}
			else if (result == 3) {
				tmp += (one + two + three);
				three = 1;
				one = 0; two = 0;
			}
			else {
				tmp += (one + two + three + 1);
				one = 0; two = 0; three = 0;
			}
			cur++; //다음 타자
		}
	}
	maxScore = max(maxScore, tmp); //최대득점
}

void MakeOrder() { 
	if (v.size() == 8) {
		vector<int> order;
		for (int i = 0; i < 8; i++){
			if (i == 3) order.push_back(0); //4번타자는 1번고정
			order.push_back(v[i]);
		}
		solve(order);
		return;
	}
	
	for (int i = 1; i < 9; i++) {
		if (!visit[i]) {
			v.push_back(i);
			visit[i] = 1;
			MakeOrder();
			v.pop_back();
			visit[i] = 0;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 9; j++) {
			cin >> value[i][j];
		}
	}
	MakeOrder();
	cout << maxScore;
}