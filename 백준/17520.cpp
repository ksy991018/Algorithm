#include <iostream>
using namespace std;

int N;
long long result = 1;

int main() {
	cin >> N;
	int tmp = (N + 1) / 2;
	while (tmp--) {
		result = (result * 2) % 16769023;
	}
	cout << result << endl;
}