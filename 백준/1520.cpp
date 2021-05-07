#include <iostream>
#include <cstring>
using namespace std;

//dfs + dp 
//핵심 : 탐색가능한 길이여도 이미 탐색했던 길이면 해당지점으로부터 갈수있는 경로의 수를 가져옴

int M, N;
int map[500][500];
int dp[500][500];   //경로의 수
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int dfs(int x, int y) {
	if (x == M-1 && y == N-1) return 1; //도착하면 경로의 수 추가
	
	if (dp[x][y] !=-1) return dp[x][y]; //방문한적 있으면 저장해놓은 해당지점에서 갈수있는 경로 수 반환

	dp[x][y] = 0; //방문 표시 
	for (int i = 0; i < 4; i++){
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx >= 0 && cx < M && cy >= 0 && cy<N  && map[x][y]> map[cx][cy]) { //범위o && 더 작은높이
			dp[x][y] += dfs(cx, cy); //경로의 수 추가
		}
	}
	return dp[x][y];
}


int main() {
	cin >> M >> N;
	memset(dp, -1, sizeof(dp)); //처음 가는길인지 아닌지 구분 위해. 
	//0으로 초기화하면 방문했어도 도착하기 전이나 탐색 진행중이라 0일수 있으므로 방문여부 구분 불가.

	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	cout << dfs(0,0);
	cout << dp[0][0];
}

//dfs만 이용 -> 시간초과
//#include <iostream>
//using namespace std;
//
//int M, N;
//int map[500][500];
//int visit[500][500];
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int cnt;
//
//void dfs(int x, int y) {
//	if (x == M-1 && y == N-1) {
//		cnt++;
//		return;
//	}
//	visit[x][y] = 1;
//	cout << x << " " << y << endl;
//	int tmp = map[x][y];
//	for (int i = 0; i < 4; i++){
//		int cx = x + dx[i];
//		int cy = y + dy[i];
//		if (cx >= 0 && cx < M && cy >= 0 && cy<N && !visit[cx][cy] && tmp> map[cx][cy]) {
//			visit[cx][cy] = 1;
//			dfs(cx, cy);
//			visit[cx][cy] = 0;
//		}
//	}
//}
//
//
//
//int main() {
//	cin >> M >> N;
//	for (int i = 0; i < M; i++){
//		for (int j = 0; j < N; j++) {
//			cin >> map[i][j];
//		}
//	}
//	dfs(0,0);
//	cout << cnt;
//}