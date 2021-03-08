#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int arr[101][2]; //�賶 ����&��ġ
int dp[101][100001]; //�賶 & �ִ빫��

int main() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++){
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = 1; i <=N; i++){
		for (int j = 0; j <= K; j++) {
			if (j >= arr[i][0]) dp[i][j] = max(dp[i-1][j - arr[i][0]] + arr[i][1], dp[i - 1][j]); //���� �賶 �����Ѱ��, ���Ѱ�� 
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[N][K];
}