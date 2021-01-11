#include <iostream>
#include <stack>
using namespace std;

string check(string ps) { //올바른 괄호 문자열 확인
	stack<char> s;
	for (int i = 0; i < ps.length(); i++) {
		if (ps[i] == '(') { //여는 괄호면 push
			s.push(ps[i]);
		}
		else if (ps[i] == ')') { //닫는 괄호면 pop
			if (s.empty()) { //pop할께 없으면 즉시종료
				return "NO";
			}
			else {
				s.pop();
			}
		}
	}
	if (s.empty()) { //끝나고 스택 비어있으면 성공
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