#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1000];
int dp[1000];
int result;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++){
		int tmp = 0;
		for (int j = 0; j < i; j++){
			if (arr[i] < arr[j]) tmp = max(tmp, dp[j]); //현재 수보다 큰수의 dp값+1
		}
		dp[i] = tmp + 1;
		result = max(result, dp[i]);
	}
	cout << result;
}
