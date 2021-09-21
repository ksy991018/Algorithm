#include <iostream>
#include <stack>
using namespace std;

int N, B;
stack<int> v;

int main() {
	cin >> N >> B;
	
	int tmp = N;
	while (tmp >= B) {
		v.push(tmp % B);
		tmp /= B;
	}
	v.push(tmp);

	while (!v.empty()) {
		int n = v.top();
		v.pop();
		if (n >= 10) cout << char(n - 10 + 'A');
		else cout << n;
	}
}