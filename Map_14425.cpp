#include <iostream>
#include <map>
using namespace std;

map<string, int> mp;
int n, m;
string s;
int main() {
	cin >> n >> m;
	while (n--) {
		cin >> s;
		mp.insert(make_pair(s,1));
	}
	int cnt = 0;
	while (m--) {
		cin >> s;
		if (mp.count(s) > 0) cnt++;
	}
	cout << cnt;
}