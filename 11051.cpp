#include <iostream>
using namespace std;

int N, K;
int dp[1001][1002];

int main() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++){ //nC0 = 1
		dp[i][0] = 1;
	}

	for (int i = 1; i <=K; i++){
		for (int j = i; j <= N; j++) {
			if (i == j) dp[j][i] = 1;
			else dp[j][i] = (dp[j - 1][i] + dp[j - 1][i - 1])% 10007;
		}
	}
	cout << dp[N][K];	
}