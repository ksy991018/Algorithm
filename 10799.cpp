#include <iostream>
#include <stack>
using namespace std;

int main() {
	string s;
	cin >> s;

	stack<char> st;
	int cnt = 0;

	bool flag = false;
	for (int i = 0; i < s.length(); i++){
		if (s[i] == '(') {
			st.push(s[i]);
			flag = true;
		}
		else if(s[i]==')'){ 
			st.pop();
			if (flag) { //��ȣ �ٷ� �������� ���� stack size��ŭ		
				cnt += st.size();
			}
			else { //�ƴϸ� Ư�� ����� ���̹Ƿ� +1
				cnt++;
			}
			flag = false;
		}
	}
	cout << cnt << endl;
}