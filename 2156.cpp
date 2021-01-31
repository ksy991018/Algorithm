#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001]; //현재 위치의 포도주 선택했을때 최댓값 
int arr[10001]; //입력
int result[10001]; //각 인덱스 상황에서 최댓값
int N;
int largest; //현재 최댓값

//현재 위치 포도주 선택했을때랑 안선택했을때 두가지 경우 고려하면 배열 2개로만 풀수있음. max(dp[i-1],max(dp[i-2],arr[i-1]+dp[i-3])+arr[i])

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
			dp[i] = max(arr[i] + arr[i - 1] + result[i - 3], result[i-2] + arr[i]); //계단문제 비슷. 다른점은 dp[i-3]& dp[i-2]가 아니라 해당 인덱스까지 진행했을때 최댓값
			if(largest < dp[i]) largest = dp[i];
			result[i] = largest;
		}
		cout << largest;
	}
}