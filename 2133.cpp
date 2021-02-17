#include <iostream>
using namespace std;

int N;
int dp[31];

// 특별한 모양: 2가지
//dp[n] = dp[n-2]*dp[2](오른쪽에 갖다 붙이는 경우) + 2*dp[n-4](타일 3x4에서만 나올수있는 2가지)
// + 2*dp[n-6] (타일 3x6에서만 나올수있는 2가지)+ ... + 2*dp[2](타일 3xn-2에서만 나올수있는 2가지) + 2(타일 3xn에서만 나올수있는 2가지)
int main() {
	cin >> N;
	dp[0] = 1; //편의상
	dp[1] = 0;
	dp[2] = 3;
	if (N % 2 != 0) cout << 0;
	else {
		for (int i = 4; i <=N; i++){
			dp[i] = dp[i - 2]*dp[2];
			for (int j = 0; j <=i-4; j=j+2){
				dp[i] += 2*dp[j];
			}	
		}
		cout << dp[N];
	}
}