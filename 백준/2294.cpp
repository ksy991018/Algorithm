#include <iostream>
#include <cmath>
#define MAX 1000000

using namespace std;

int coin[101];
int dp[10001];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++){
		cin >> coin[i];
	}

	dp[0] = 0;
	for (int i = 1; i <= k; i++){
		dp[i] = MAX;
	}

	for (int i = 1; i <=k ; i++){
		for (int j = 0; j < n; j++) {
			if(i-coin[j]>=0)
				dp[i] = fmin(dp[i], dp[i - coin[j]] + 1);
		}
	}

	if (dp[k] == MAX)
		cout << -1;
	else
		cout << dp[k];


}