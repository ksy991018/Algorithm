#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string s;
	string result;
	getline(cin, s);

	bool flag = false;
	stack<char> st;
	for (int i = 0; i < s.length(); i++){
		if (s[i] == ' ') {
			while (!st.empty()) {
				result += st.top();
				st.pop();
			}
			cout << result << " ";
			result = "";
			continue;
		}
		if (s[i] == '<') {
			while(!st.empty()) {
				result += st.top();
				st.pop();
			}
			flag = true;
		}
		if (flag) {
			result += s[i];
			if (s[i] == '>') flag = false;
		}
		else {
			st.push(s[i]);
		}
	}
	while (!st.empty()) {
		result += st.top();
		st.pop();
		
	}
	cout << result;

	
}