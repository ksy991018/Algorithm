#include <iostream>
using namespace std;

int N;
long long dp[91]; //����Ʈ

int main() {
	cin >> N;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <=N; i++){
		dp[i] = dp[i - 1] + dp[i - 2]; //�Ǹ������ڸ��� 0�϶� dp[i-1] / 1�϶��� �׾��ڸ��� 0���� �����̹Ƿ� dp[i-2]
	}
	cout << dp[N];
}