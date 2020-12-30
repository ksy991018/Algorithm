#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> q;
int N;

int main() {
	cin >> N;
	string command;
	for (int i = 0; i < N; i++){
		cin >> command;

		if (command == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (command == "pop") {
			if (q.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (command == "size") {
			cout << q.size() << endl;
		}
		else if (command == "empty") {
			if (q.empty()) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
		else if (command == "front") {
			if (q.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << q.front() << endl;
			}
		}
		else if (command == "back") {
			if (q.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << q.back() << endl;
			}
		}
	}
}