#include <iostream>
#include <algorithm>
using namespace std;

int N; //카드수
int dp[1001]; //dp[i]: i장갖기위한 최대금액
int price[1001];

int main() {
	cin >> N; 
	for (int i = 1; i <= N; i++){
		cin >> price[i];
	}

	for (int i = 1; i <=N; i++){
		int maxPrice = price[i]; //i장들어있는 카드팩 가격을 기본값
		for (int j = 1; j <= i/2; j++){  //i장보다 적은 카드팩들 조합이 더 좋으면 swap
			if (maxPrice < dp[j] + dp[i - j]) maxPrice = dp[j] + dp[i - j];
		}
		dp[i] = maxPrice;
	}
	cout << dp[N];
}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//int N;
//int arr[1001];
//int visit[1001];
//int maxPrice;
//vector<int> v;
//
//void solve(int sum) {
//	if (sum > N) return;
//	if (sum == N) {
//		int result = 0;
//		for (int i = 0; i < v.size(); i++){
//			result += arr[v[i]];
//		}
//		if (maxPrice < result) maxPrice = result;
//		return;
//	}
//
//	for (int i = 1; i <= N; i++){
//		if (visit[i]<N) {
//			visit[i] += i;
//			v.push_back(i);
//			solve(sum + i);
//			v.pop_back();
//			visit[i]-=i;
//		}
//	}
//}
//
//int main() {
//	cin >> N;
//	for (int i = 1; i <= N; i++){
//		cin >> arr[i];
//	}
//
//	solve(0);
//	cout << maxPrice;
//}