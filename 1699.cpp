#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[100001]; //최소수 저장


int main() {
	cin >> N;
	
	for (int i = 1; i*i <= N; i++){ //N보다 작은수 1로
		dp[i *i] = 1;
	}
	for (int i = 1; i <=N; i++){
		if (!dp[i]) {//제곱수아닐때 
			int tmp = 1000000;
			for (int j = 1; j*j < i; j++) { //제곱수를 포함해서 현재수 만들수 있는 경우
				tmp = min(tmp, dp[j*j] + dp[i - j*j]); //
			}
			dp[i] = tmp;
		}
	}
	cout << dp[N];
}