#include <iostream>
#include <algorithm>
#include <iomanip>
#define INF 100000000 //10�� ���ϴ� Ʋ��
using namespace std;

int T, K;
int dp[501][501];  //dp[a][b] : A���� B���� ��ġ�µ� �ּҺ��
int sum[501][501]; //sum[a][b] : A���� B���� ��

//Ǯ�� : (p,q) = min[ (p,p)+(p+1,q) , (p,p+1)+(p+2,q), (p,p+2)+(p+3,q) ... , (p,q-1)+(q,q) ] + sum[p][q] ->�밢������ �Ʒ����� ���� ä������
//�ð����⵵ O(N^2)

int main() {
	cin >> T;

	while (T--) {
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> sum[i][i];
			for (int j = 1; j < i; j++) { //�밢�� ���� ������
				sum[j][i] = sum[j][i - 1] + sum[i][i];
			}
		}
		//cout << "sum : " << endl;
		//for (int i = 1; i <= K; i++) {
		//	for (int j = 1; j <= K; j++) {
		//		cout << setw(4) << sum[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		for (int i = 1; i <= K; i++) {
			for (int j = i - 1; j >= 1; j--) {
				//dp[j][i]
				int tmp = INF;
				for (int k = j; k <= i - 1; k++) { //������ �밢������ �Ʒ����� ����
					tmp = min(tmp, dp[j][k] + dp[k + 1][i]);
				}
				dp[j][i] = tmp + sum[j][i];
			}
		}
		//cout << "dp : " << endl;
		//for (int i = 1; i <= K; i++) {
		//	for (int j = 1; j <= K; j++) {
		//		cout << setw(4) << dp[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		cout << dp[1][K] << endl;


	}

}