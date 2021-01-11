#include <iostream>
#include <stack>
using namespace std;

string check(string ps) { //�ùٸ� ��ȣ ���ڿ� Ȯ��
	stack<char> s;
	for (int i = 0; i < ps.length(); i++) {
		if (ps[i] == '(') { //���� ��ȣ�� push
			s.push(ps[i]);
		}
		else if (ps[i] == ')') { //�ݴ� ��ȣ�� pop
			if (s.empty()) { //pop�Ҳ� ������ �������
				return "NO";
			}
			else {
				s.pop();
			}
		}
	}
	if (s.empty()) { //������ ���� ��������� ����
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