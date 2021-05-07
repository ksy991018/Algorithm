#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T, N;
int dp[2][100000]; //�ڱ��ڽ� �����ؼ� ������� ��ƼĿ �̾����� ���� �ִ� ����

int main() {
	cin >> T;
	while (T--) {
		cin >> N;

		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < N; j++) {
				cin >> dp[i][j]; //�ڱ��ڽŰ����� �ʱ�ȭ
			}
		}

		dp[0][1] += dp[1][0]; //2��° �������� dp�� ����
		dp[1][1] += dp[0][0];
		
		for (int i = 2; i < N; i++) {
			for (int j = 0; j < 2; j++) {
				if (j == 0) dp[j][i] += max(dp[0][i - 2], max(dp[1][i - 2], dp[1][i - 1])); //�����̸�, max(�ٷ� �� �Ʒ���, ���� ����,���� �Ʒ���)
				else dp[j][i] += max( dp[0][i - 2], max(dp[1][i - 2], dp[0][i - 1] )); //�Ʒ����̸�,  max(�ٷ� �� ����, ���� ����,���� �Ʒ���)
			}
		}
		cout << max(dp[0][N-1],dp[1][N-1]) << "\n";
	}
}