#include <iostream>
using namespace std;

int dp[11] = { 1,1,2 },n,k;

void calc(int k) {
	for (int i = 3; i <= k; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> k;
		calc(k);
		cout << dp[k] << endl;
	}
}