#include <iostream>
#include <stack>
using namespace std;

string s;
stack<char> c;
int flag = 0;
int result;
int out;
int tmp = 1;

//�й��Ģ . ���� ��ȣ�϶� tmp�� �ø� & ��ȣ �ٷ� �������� result�� ������.
// (()[[]]) = 2*(2+3*(3)) = 2*2 + 2*3*3   

int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') { //���� ��ȣ�϶� tmp������
			tmp *= 2;
			c.push('(');
		}
		else if (s[i] == '[') {
			tmp *= 3;
			c.push('[');
		}
		else if (c.empty() || (c.top() == '(' && s[i] != ')') || (c.top() == '[' && s[i] != ']')) { //����ְų� ��ȣ�� �ȸ�����
			flag = 1;
			break;
		}
		else if (s[i] == ']') {
			if (s[i - 1] == '[') { //�ٷ� ������
				result += tmp;
			}
			c.pop();
			tmp /= 3; //��ȣ �ϳ� ������ ����
		}
		else if (s[i] == ')') {
			if (s[i - 1] == '(') { //�ٷ� ������ 
				result += tmp;
			}
			c.pop();
			tmp /= 2;
		}

	}
	if (flag || !c.empty()) cout << 0;
	else cout << result;
}