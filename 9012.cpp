#include <iostream>
#include <stack>
using namespace std;

string check(string ps) { //올바른 괄호 문자열 확인
	stack<char> s;
	for (int i = 0; i < ps.length(); i++) {
		if (ps[i] == '(') {
			s.push(ps[i]);
		}
		else if (ps[i] == ')') {
			if (s.empty()) {
				return "NO";
			}
			else {
				s.pop();
			}
		}
	}
	if (s.empty()) {
		return "YES";
	}
	else {
		return "NO";
	}
}

int main() {
	int N;
	string ps;
	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> ps;
		cout << check(ps) << endl;
	}
}