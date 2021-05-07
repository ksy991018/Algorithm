#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int N, K;
stack<char> st;
stack<char> res;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> K;

	string s;
	cin >> s;
	for (int i = 0; i < N; i++){
		while (!st.empty() && K > 0 && st.top() < s[i]) {
			st.pop();
			K--;
		}
		st.push(s[i]);
	}

	while (K--) {
		st.pop();
	}

	//앞에것부터 출력
	while (!st.empty()) {
		res.push(st.top());
		st.pop();
	}

	while (!res.empty()) {
		cout << res.top();
		res.pop();
	}
}