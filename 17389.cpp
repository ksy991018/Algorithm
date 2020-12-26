#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string ans;
	cin >> ans;
	int res = 0;
	int bonus = 0;
	for (int i = 0; i < n; i++){
		if (ans[i] == 'O') {
			res += i+1;
			res += bonus;
			bonus++;
		}
		else if (ans[i] == 'X') {
			bonus = 0;
		}
	}

	cout << res << endl;
}