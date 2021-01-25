#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[1001][4];
int cost[1001][4];

int main() {
	cin >> N;

	for (int i = 1; i <=N; i++){
		for (int j = 1; j <= 3; j++){
			cin >> cost[i][j];
		}
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + cost[i][1]; //»¡°­¼±ÅÃ
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + cost[i][2]; //ÃÊ·Ï
		dp[i][3] = min(dp[i - 1][2], dp[i - 1][1]) + cost[i][3]; //ÆÄ¶û
	}
	cout << min({ dp[N][1],dp[N][2],dp[N][3] }) << endl;
}