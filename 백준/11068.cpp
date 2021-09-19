#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int T,N;

int solve(int N) {
	for (int i = 2; i <=64; i++){ //iÁø¹ý
		stack<int> s;
		queue<int> q;
		int tmp = N;
		bool flag = true;
		while (tmp>=i) {
			s.push(tmp % i);
			q.push(tmp % i);
			tmp /= i;
		}
		s.push(tmp); q.push(tmp);
		while (!s.empty()) {
			if (s.top() != q.front()) {
				flag = false;
				break;
			}
			s.pop(); q.pop();
		}
		if (flag) return 1;
		
	}
	return 0;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		cout << solve(N) << endl;
	}
}