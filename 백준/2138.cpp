#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int N;
string start, target;
int cnt;

void swap(string& s, int i) {//i번째 스위치 누르기
	for (int j = i - 1; j <= i + 1; j++) {
		if (j < 0 || j >= N) continue;
		if (s[j] == '1') s[j] = '0';
		else s[j] = '1';
	}
}

int solve(string a, bool include) {
	int tmpcnt = 0;
	if (include) { //처음 0번째 전구 바꾸고 시작하는 경우
		swap(a, 0);
		tmpcnt++;
	}
	for (int i = 1; i < N; i++) {//1번째~N-1번째 전구 바꾸기
		if (a[i - 1] != target[i - 1]) {//i-1번째 전구에 영향주는건 i번 스위치뿐 
			swap(a, i);
			tmpcnt++;
		}
	}
	if (a == target) return tmpcnt; //만들고자 하는 상태일때 
	else return INF;

}

int main() {
	cin >> N;
	cin >> start >> target;

	cnt = min(solve(start, true),solve(start,false));//0번째 전구 누를때 안누를때 2가지 케이스 
	cout << (cnt == INF ? -1 : cnt) << endl;
}
