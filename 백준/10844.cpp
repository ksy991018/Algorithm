#include <iostream>
#define MOD 1000000000

using namespace std;

int N;
long long dp[101][11]; //�� �ε������� 0~9 ���ü��ִ� ��ܼ�

//�� �ڸ����� 0~9������ ��� �� ����
int main() {
	cin >> N;
	dp[1][0] = 0; //0���� �����ϴ¼� x
	for (int i = 1; i <= 9; i++){
		dp[1][i] = 1;
	}

	for (int i = 2; i <=N; i++){
		for (int j = 0; j <=9; j++){
			if (j == 0) {//0�� ������ 1�� ���� ��ܼ���
				dp[i][j] = dp[i - 1][1];
			}
			else if (j == 9) {//9�� ������ 8�� ���� ��ܼ���
				dp[i][j] = dp[i - 1][8];
			}
			else {//�Ϲ����� ���: J�� ������ J-1 / J+1�� ���� ��ܼ���
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