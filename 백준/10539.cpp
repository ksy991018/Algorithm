#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[100];
	int b[100];
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		b[i] = (i + 1) * a[i] - tmp;
		tmp += b[i];
	}

	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
}