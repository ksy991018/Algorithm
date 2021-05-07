#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int map[1000][1000];
int check[1000][1000]; //토마토 익은 날짜
queue<pair<int, int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cnt;

int bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++){
			int cx = x + dx[i];
			int cy = y + dy[i];
			//포인트
			int tmp = check[x][y]; 
			if (cx >= 0 && cx <= N-1 && cy >= 0 && cy <= M-1) {
				if (map[cx][cy] == 0) {
					map[cx][cy] = 1;
					q.push(make_pair(cx, cy)); //익은 토마토 저장
					check[cx][cy] = tmp + 1; //익은 날짜 +1해주기
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] > cnt) cnt = check[i][j]; //익은 날짜중 max찾기
			if (map[i][j] == 0) return -1; //안익은토마토 있으면 바로 out
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push(make_pair(i, j)); //익은 토마토 저장
				check[i][j] = 0; //처음이니까 0
			}
		}
	}
	cout << bfs();
}