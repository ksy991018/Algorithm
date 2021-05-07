#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001]; //���� ��ġ�� ������ ���������� �ִ� 
int arr[10001]; //�Է�
int result[10001]; //�� �ε��� ��Ȳ���� �ִ�
int N;
int largest; //���� �ִ�

//���� ��ġ ������ ������������ �ȼ��������� �ΰ��� ��� ����ϸ� �迭 2���θ� Ǯ������. max(dp[i-1],max(dp[i-2],arr[i-1]+dp[i-3])+arr[i])

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[2] + arr[3], dp[1] + arr[3]);
	
	if (N == 1) cout << dp[1];
	else if (N == 2) cout << dp[2];
	else if (N == 3) cout << max(dp[2],dp[3]);
	else {
		result[1] = dp[1];
		result[2] = dp[2];
		result[3] = max({ dp[1],dp[2],dp[3] });
		largest = max({ result[1],result[2],result[3] });
		for (int i = 4; i <= N; i++) {
			dp[i] = max(arr[i] + arr[i - 1] + result[i - 3], result[i-2] + arr[i]); //��ܹ��� ���. �ٸ����� dp[i-3]& dp[i-2]�� �ƴ϶� �ش� �ε������� ���������� �ִ�
			if(largest < dp[i]) largest = dp[i];
			result[i] = largest;
		}
		cout << largest;
	}
}