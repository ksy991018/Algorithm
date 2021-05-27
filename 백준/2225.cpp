#include <iostream>
using namespace std;
#define INF 1000000000

int N, K;
long long dp[201][201]; //dp[K][N] : K�� �����ؼ� ���� N�� ����Ǽ� 

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i <= N; i++){ //1�������� i����°�� �ڱ��ڽŻ� 
		dp[1][i] = 1;
	}

	for (int i = 2; i <=K ; i++){
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k]; //�� j ������� (i-1)�� �����ؼ� ���� k�ΰ�� + 1�������ؼ� j-k�ΰ�� �ڵ����� ������Ƿ� 
			}
			dp[i][j] %= INF;
		}
	}

	cout << dp[K][N] <<endl;
}