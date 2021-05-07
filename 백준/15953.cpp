#include <iostream>
using namespace std;


int setA(int a) {
	if (a == 0 || a>21) {
		return 0;
	}
	else if (a == 1 ) {
		return 500;
	}
	else if (a <= 3) {
		return 300;
	}
	else if (a <= 6) {
		return 200;
	}
	else if (a <= 10) {
		return 50;
	}
	else if (a <= 15) {
		return 30;
	}
	else if (a <= 21) {
		return 10;
	}
}

int setB(int b) {
	if (b == 0 || b>31) {
		return 0;
	}
	else if (b == 1) {
		return 512;
	}
	else if (b <= 3) {
		return 256;
	}
	else if (b <= 7) {
		return 128;
	}
	else if (b <= 15) {
		return 64;
	}
	else if (b <= 31) {
		return 32;
	}
}
int main() {
	int n;
	cin >> n;
	int result[1000] = { 0, };

	for (int i = 0; i < n; i++){
		int a;
		int b;
		cin >> a >> b;
		result[i]= 10000*(setA(a)+setB(b));
	}
	for (int i = 0; i < n; i++) {
		cout << result[i] << endl;
	}
}