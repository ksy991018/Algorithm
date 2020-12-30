#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> s;
int n;

int main() {
	cin >> n;
	string command;

	for (int i = 0; i < n; i++){
		cin >> command;
		if (command == "push") {
			int num;
			cin >> num;
			s.push(num);
		}
		else if (command == "pop") {
			if (s.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (command == "size") {
			cout << s.size() << endl;
		}
		else if (command == "empty") {
			if (s.empty()) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
		else if (command == "top") {
			if (s.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << s.top() << endl;
			}
		}
	}
}