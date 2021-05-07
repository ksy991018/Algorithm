#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T, N;
int dp[2][100000]; //자기자신 포함해서 현재까지 스티커 뽑았을때 점수 최댓값 저장

int main() {
	cin >> T;
	while (T--) {
		cin >> N;

		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < N; j++) {
				cin >> dp[i][j]; //자기자신값으로 초기화
			}
		}

		dp[0][1] += dp[1][0]; //2번째 열까지는 dp값 직접
		dp[1][1] += dp[0][0];
		
		for (int i = 2; i < N; i++) {
			for (int j = 0; j < 2; j++) {
				if (j == 0) dp[j][i] += max(dp[0][i - 2], max(dp[1][i - 2], dp[1][i - 1])); //윗줄이면, max(바로 전 아랫줄, 전전 윗줄,전전 아랫줄)
				else dp[j][i] += max( dp[0][i - 2], max(dp[1][i - 2], dp[0][i - 1] )); //아랫줄이면,  max(바로 전 윗줄, 전전 윗줄,전전 아랫줄)
			}
		}
		cout << max(dp[0][N-1],dp[1][N-1]) << "\n";
	}
}