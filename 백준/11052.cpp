#include <iostream>
#include <algorithm>
using namespace std;

int N; //ī���
int dp[1001]; //dp[i]: i�尮������ �ִ�ݾ�
int price[1001];

int main() {
	cin >> N; 
	for (int i = 1; i <= N; i++){
		cin >> price[i];
	}

	for (int i = 1; i <=N; i++){
		int maxPrice = price[i]; //i�����ִ� ī���� ������ �⺻��
		for (int j = 1; j <= i/2; j++){  //i�庸�� ���� ī���ѵ� ������ �� ������ swap
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