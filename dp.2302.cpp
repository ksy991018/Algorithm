#include <iostream>
using namespace std;

int dp[42] = { 1,1,2 }, fix, N, k;
int result=1;
int tmp = 0;

int main() {
	cin >> N;
	cin >> fix;

	for (int i = 3; i <= N; i++){
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	for (int i = 0; i < fix; i++){
		cin >> k;
		result *= dp[k-tmp-1];
		tmp = k;
	}
	result *= dp[N - tmp];
	cout << result << endl;
}