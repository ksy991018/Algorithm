#include <iostream>
#define MOD 1000000000

using namespace std;

int N;
long long dp[101][11]; //각 인덱스에서 0~9 나올수있는 계단수

//각 자릿수가 0~9나오는 경우 다 구함
int main() {
	cin >> N;
	dp[1][0] = 0; //0으로 시작하는수 x
	for (int i = 1; i <= 9; i++){
		dp[1][i] = 1;
	}

	for (int i = 2; i <=N; i++){
		for (int j = 0; j <=9; j++){
			if (j == 0) {//0은 그전에 1로 끝난 계단수에
				dp[i][j] = dp[i - 1][1];
			}
			else if (j == 9) {//9는 그전에 8로 끝난 계단수에
				dp[i][j] = dp[i - 1][8];
			}
			else {//일반적인 경우: J는 그전에 J-1 / J+1로 끝난 계단수에
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%MOD;
			}
		}
	}

	long long result=0;
	for (int i = 0; i <=9 ; i++){
		result += dp[N][i];
	}
	cout << result%MOD;
}