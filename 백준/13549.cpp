#include <iostream>
#include <queue>
#define INF 10000000
using namespace std;

int N, K; //수빈,동생 위치
int visit[100001]; //최소 도착시간 저장

int bfs() {
	queue<int> q;
	q.push(N);
	visit[N] = 0; //현재위치

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == K) return visit[K]; //동생만남
		if (x - 1 < 100001 && visit[x - 1] > visit[x] + 1) { //최소 도착시간 
			visit[x - 1] = visit[x] + 1;
			q.push(x - 1);
		}
		if (x + 1 < 100001 && visit[x + 1] > visit[x] + 1) {
			visit[x + 1] = visit[x] + 1;
			q.push(x + 1);
		}
		if (2 * x < 100001 && visit[2 * x]>visit[x]) {
			visit[2 * x] = visit[x];
			q.push(2 * x);
		}
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < 100001; i++){ 
		visit[i]=INF;
	}
	cout << bfs();
}

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int N, K;
//int dp[100001];
//
//int main() {
//	cin >> N >> K;
//	dp[N] = 0;
//
//	
//	for (int i = N-1; i >=0 ; i--){
//		dp[i] = dp[i+1]+1;
//	}
//	if (K <= N) cout << dp[K];
//	else {
//		for (int i = N + 1; i <= K; i++){
//			if (i % 2 != 0) dp[i] = dp[i - 1] + 1;
//			else dp[i] = min(dp[i - 1]+1,dp[i/2]);
//		}
//		cout << dp[K];
//	}
//
//}