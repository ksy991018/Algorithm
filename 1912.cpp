#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int N;
int dp[100000];
int arr[100000]; 

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	dp[0] = arr[0];
	int max = dp[0];
	for (int i = 1; i < N; i++){
		dp[i] = fmax(dp[i - 1] + arr[i], arr[i]); //현재 숫자를 포함해서 선택했을때 가장큰합(수는 한개이상 선택해야하므로)
		if (max < dp[i]) max = dp[i]; //통틀어서 큰합
		cout << dp[i] << " " << max << endl;
	}
	cout << max;
}


//int main() {
//	ios_base::sync_with_stdio(false);
//	scanf("%d", &N);
//	int max=-1000;
//	for (int i = 0; i < N; i++){
//		int n;
//		scanf("%d", &n);
//		int tmp = dp[0]; //3
//		if (n > max) max = n;
//		dp[0] = n; //1
//		for (int j = 1; j <= i; j++){
//			int curr = dp[j]; 
//			if (n + tmp > max) max = n + tmp;
//			dp[j] = n + tmp; 
//			tmp = curr; 
//		}
//	}
//	cout << max << "\n";
//}