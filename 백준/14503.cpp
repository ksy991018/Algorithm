#include <iostream>
using namespace std;

int N, M;
int map[50][50];
int c[50][50];
int cnt;
int dx[4] = { -1,0,1,0 }; //순서 중요
int dy[4] = { 0,1,0,-1 };

void dfs(int x, int y, int dir) {
	if (!c[x][y]) {
		c[x][y] = 1;
		cnt++;
	}
	bool flag = true;
	for (int i = 0; i < 4; i++) {
		dir -= 1;
		if (dir < 0) dir = 3;
		int cx = x + dx[dir]; //이게포인트
		int cy = y + dy[dir];
		if (cx >= 0 && cx <= N - 1 && cy >= 0 && cy <= M - 1) {
			if (!map[cx][cy] && !c[cx][cy]) { //벽도 아니고 지나간적 없을때
				dfs(cx, cy, dir);
				flag = false;
				break;
			}
		}
	}
	if (flag) { //양쪽 꽉 막혔을때 (벽이거나, 지나갔거나)
		//후진
		int cx = x - dx[dir]; //포인트
		int cy = y - dy[dir];
		if (cx >= 0 && cx <= N - 1 && cy >= 0 && cy <= M - 1) {
			if (!map[cx][cy]) { //벽아닐때
				dfs(cx, cy, dir); 
			}
		}
	}
}

int main() {
	cin >> N >> M;

	int x, y, dir;
	cin >> x >> y >> dir;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			int n;
			cin >> n;
			map[i][j] = n;
		}
	}

	dfs(x, y,dir);

	cout << cnt << "\n";
}