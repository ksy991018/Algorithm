#include <iostream>
using namespace std;

int N;
int dp[31];

// Ư���� ���: 2����
//dp[n] = dp[n-2]*dp[2](�����ʿ� ���� ���̴� ���) + 2*dp[n-4](Ÿ�� 3x4������ ���ü��ִ� 2����)
// + 2*dp[n-6] (Ÿ�� 3x6������ ���ü��ִ� 2����)+ ... + 2*dp[2](Ÿ�� 3xn-2������ ���ü��ִ� 2����) + 2(Ÿ�� 3xn������ ���ü��ִ� 2����)
int main() {
	cin >> N;
	dp[0] = 1; //���ǻ�
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