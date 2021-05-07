#include <iostream>
using namespace std;

int N;

int main() {
	cin >> N;

	int tmp = N / 5; //1
	bool flag = true;
	while (flag && tmp) {
		int n = N; 
		if (n % (5 * tmp) == 0) {
			cout << tmp << "\n";
			flag = false;
			break;
		}
		n -= (5 * tmp); //6
		if (n % 3 == 0) {
			cout << tmp + n / 3 << "\n";
			flag = false;
			break;
		}
		tmp--;
	}
	if (flag) {
		if (N % 3 == 0) {
			cout << N / 3 << "\n";
		}
		else {
			cout << "-1\n";
		}
		
	}
}