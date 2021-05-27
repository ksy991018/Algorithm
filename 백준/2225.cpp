#include <iostream>
using namespace std;
#define INF 1000000000

int N, K;
long long dp[201][201]; //dp[K][N] : K개 선택해서 합이 N인 경우의수 

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i <= N; i++){ //1개가지고 i만드는경우 자기자신뿐 
		dp[1][i] = 1;
	}

	for (int i = 2; i <=K ; i++){
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k]; //합 j 만들려면 (i-1)개 선택해서 합이 k인경우 + 1개선택해서 j-k인경우 자동으로 따라오므로 
			}
			dp[i][j] %= INF;
		}
	}

	cout << dp[K][N] <<endl;
}