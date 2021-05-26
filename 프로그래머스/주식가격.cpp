#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	stack<int> s;
	int size = prices.size(); // 계속 size를 계산하는 것보다 상수값으로 저장하면 전체 함수 처리 시간 감소

	for (int i = 0; i < size; ++i) {
		cout << i << "번째" << endl;
		while (!s.empty() && prices[s.top()] > prices[i]) { // 가격이 줄어들었다면
			cout << s.top() <<  ": ";
			answer[s.top()] = i - s.top(); // 현재 시간 - 당시 시간
			cout << answer[s.top()] << endl;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		answer[s.top()] = size - 1 - s.top(); // 종료 시간 - 당시 시간
		s.pop();
	}

	return answer;
}


int main() {
	vector<int> v = solution({ 1,2,3,2,1 });
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}