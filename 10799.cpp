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
			if (flag) { //괄호 바로 닫힐때는 남은 stack size만큼		
				cnt += st.size();
			}
			else { //아니면 특정 막대기 끝이므로 +1
				cnt++;
			}
			flag = false;
		}
	}
	cout << cnt << endl;
}