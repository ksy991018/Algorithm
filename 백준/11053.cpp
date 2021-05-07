#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1001];
int dp[1001];//가장긴 증가하는 부분수열 개수
int best=1;//0으로 하면 N이 1일경우 틀림

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	dp[0] = 1;
	for (int i = 1; i < N; i++){
		int tmp=0;
		for (int j = 0; j < i; j++){
			if (arr[j] < arr[i]) { //현재수 보다 작은 수들의 dp중 제일큰값 +1
				tmp = max(dp[j], tmp);
			}
		}
		dp[i] = tmp + 1;
		if (best < dp[i]) best = dp[i];		//dp값중 제일큰값	
	}
	cout << best;
}