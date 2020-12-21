#include <iostream>
using namespace std;

int n, k, coin[101], value[10001] = { 0, };

int main() {

	cin >> n >> k ;

	for (int i = 1; i <= n; i++){
		cin >> coin[i];
	}

	value[0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k; j++) {
			if (coin[i] <= j) {
				value[j] += value[j - coin[i]];
			}
		}
	}

	cout << value[k];

}

