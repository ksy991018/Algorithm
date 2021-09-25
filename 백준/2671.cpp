#include <iostream>
using namespace std;

string s;

int main() {
	cin >> s;
	bool flag = true;

	int cur = 0;
	while (flag && cur<s.size()) {
		if (s[cur] == '0') {
			if (cur + 1 < s.size() && s[cur + 1] == '1') {
				cur += 2;
			}
			else flag = false;
		}
		else {//1�ν���
			int zerocnt = 0;
			while (cur< s.size() && s[++cur] == '0') zerocnt++; //100~1 �κа˻�
			if (zerocnt < 2 || cur==s.size()) flag = false; //0�� 2�� �̸��̰ų� 1�� ���ڶ�� ���
			else {//100~1���� ���. 100~1~Ȯ��
				cur++; //100~1 �����ε��� 
				while (true) {
					if (cur >= s.size() || s[cur] == '0') break; //���� ����ų� 2���� ���� ����
					if (cur + 2 < s.size() && s.substr(cur, 3) == "100") break; //100�̸� 1��° ���� ����
					else if (cur + 2 < s.size() && s.substr(cur, 3) == "101") { //101�̸� 0���� 2�������� ����
						cur++;
						break;
					}
					cur++; //1�ν��������� 101,100������ �ƴѰ��
				}
			}

		}
	}
	cout << (flag ? "SUBMARINE" : "NOISE") << endl;
}

//#include <iostream>
//#include <regex>
//using namespace std;
//
//int main() {
//	string s;
//	cin >> s;
//	cout << (regex_match(s, regex("(100+1+|01)+")) ? "SUBMARINE": "NOISE") << endl;
//}