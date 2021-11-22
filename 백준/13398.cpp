#include <iostream>
#include <algorithm>
using namespace std;

int N;
int a[100000];
int dp[100000][2]; //[][0] -> 아직 삭제 x  & [][1] -> 삭제 사용
int result;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	result = a[0];
	dp[0][0] = a[0];
	for (int i = 1; i < N; i++) {
		dp[i][0] = max(dp[i - 1][0] + a[i], a[i]); 
		dp[i][1] = max(dp[i - 1][1] + a[i], dp[i - 1][0]); 
		result = max({ result, dp[i][0], dp[i][1] });
	}
	cout << result << endl;
}