#include <iostream>
#include <cmath>
using namespace std;

int dp[1000][1000] = { 0, };

int main() {
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			cin >> dp[i][j];
		}
	}

	for (int i = 1; i < N; i++) {
		dp[i][0] += dp[i - 1][0];
	}

	for (int i = 1; i < M; i++) {
		dp[0][i] += dp[0][i - 1];
	}


	for (int i = 1; i < N; i++){
		for (int j = 1; j < M; j++) {
			dp[i][j] += fmax(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	cout << dp[N - 1][M - 1] << endl;
}