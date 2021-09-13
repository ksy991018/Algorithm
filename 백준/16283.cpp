#include <iostream>
using namespace std;

int a, b, n, w;
int A, B;
int main() {
	cin >> a >> b >> n >> w;
	int cnt = 0;
	for (int i = 1; i <n ; i++){
		if (a * i + b * (n - i) == w) {
			A = i; B = n - i;
			cnt++;
		}
	}
	if (cnt == 1) {
		cout << A << " " << B << endl;
	}
	else {
		cout << -1 << endl;
	}
}