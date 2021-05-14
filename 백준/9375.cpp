#include <iostream>
#include <map>
using namespace std;

int T;
int n;


int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		map<string, int> m;
		for (int i = 0; i < n; i++){
			string a, b;
			cin >> a >> b;
			m[b]++;
		}
		int result = 1;
		for (auto i = m.begin(); i != m.end(); i++){
			result *= (i->second + 1);
		}
		cout << result-1 << endl;
	}
}