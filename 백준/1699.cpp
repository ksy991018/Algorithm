#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[100001]; //�ּҼ� ����


int main() {
	cin >> N;
	
	for (int i = 1; i*i <= N; i++){ //N���� ������ 1��
		dp[i *i] = 1;
	}
	for (int i = 1; i <=N; i++){
		if (!dp[i]) {//�������ƴҶ� 
			int tmp = 1000000;
			for (int j = 1; j*j < i; j++) { //�������� �����ؼ� ����� ����� �ִ� ���
				tmp = min(tmp, dp[j*j] + dp[i - j*j]); //
			}
			dp[i] = tmp;
		}
	}
	cout << dp[N];
}