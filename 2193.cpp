#include <iostream>
using namespace std;

int N;
long long dp[91]; //포인트

int main() {
	cin >> N;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <=N; i++){
		dp[i] = dp[i - 1] + dp[i - 2]; //맨마지막자리가 0일때 dp[i-1] / 1일때는 그앞자리는 0으로 고정이므로 dp[i-2]
	}
	cout << dp[N];
}