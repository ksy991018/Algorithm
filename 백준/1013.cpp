#include <iostream>
#include <regex>
#include <string>
using namespace std;

int T;
string s;

int main() {
	cin >> T;
	while (T--) {
		cin >> s;
		cout << (regex_match(s, regex("(100+1+|01)+")) ? "YES" : "NO") << endl;
	}
}