#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

int N;
priority_queue<int,vector<int>,greater<int>> positive; //양수
priority_queue<int,vector<int>,greater<int>> negative; //음수(우선순위{)

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		int n;
		cin >> n;
		if (n > 0) {
			positive.push(n);
		}
		else if (n < 0) {
			negative.push(abs(n)); //절댓값
		}
		else {//가장작은값 출력
			if (positive.empty() && negative.empty()) {
				cout << 0 << "\n";
			}
			else if (positive.empty()) {
				cout << -1*negative.top() << "\n"; //-1 곱하기
				negative.pop();
			}
			else if (negative.empty()) {
				cout << positive.top() << "\n";
				positive.pop();
			}
			else if (positive.top() < negative.top()) { //같거나 pos가 더 작으면 우선순위가 neg
				cout << positive.top() << "\n";
				positive.pop();
			}
			else {
				cout << -1*negative.top() << "\n";
				negative.pop();
			}
		}
	}
}