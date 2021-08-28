//이차원
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int N,n;
//long long dp[101][21]; //i번째 인덱스까지 j를 만드는 방법 
//int a[101];
//
////dp[i][j] = dp[i-1][j-a[i]] + dp[i-1][j+a[i]]
//
//int main() {
//	cin >> N;
//	for (int i = 0; i < N; i++) cin >> a[i];
//	
//	dp[0][a[0]] = 1; //맨처음수
//	for (int i = 1; i < N-1; i++) {
//		for (int j = 0; j <=20 ; j++) {
//			int next;
//			for (int k = 0; k < 2; k++) {
//				if (k == 0) next = j+a[i]; 
//				else next = j - a[i];
//				if (next >= 0 && next <= 20) { //범위 내에있으면
//					dp[i][next] += dp[i-1][j];
//				}
//			}
//		}
//	}
//	cout << dp[N - 2][a[N - 1]];
//}

//일차원
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, n;
long long dp[21];
long long dp_copy[21];

int main() {
	cin >> N;
	cin >> n; dp[n] = 1;
	for (int i = 1; i < N; i++) {
		cin >> n;
		if (i == N - 1) {
			cout << dp[n] << endl;
			return 0;
		}
		memset(dp_copy, 0, sizeof(dp_copy));
		for (int j = 0; j < 21; j++) {
			if (j + n <= 20) dp_copy[j + n] += dp[j];
			if (j - n >= 0) dp_copy[j - n] += dp[j];
		}
		copy(dp_copy, dp_copy + 21, dp);
	}
}