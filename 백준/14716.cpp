#include <iostream>
#include <queue>
using namespace std;

int M, N;
int map[250][250];
int dx[8] = { -1,-1,-1,0,0,1,1,1 }; //상하좌우대각
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
int visit[250][250];
int cnt;
queue<pair<int,int>> q;

bool isInside(int x, int y) {
	if (x >= 0 && x < M && y >= 0 && y < N && map[x][y]==1) return true;
	else return false;
}

void solve(int x, int y) { //dfs
	if (visit[x][y]) return;

	visit[x][y] = 1;
	for (int i = 0; i < 8; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (isInside(cx, cy) && !visit[cx][cy]) {			
			solve(cx, cy);
		}
	}
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j]) q.push({ i,j });
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (!visit[x][y]) {
			solve(x, y);
			cnt++;
		}
	}
	cout << cnt << endl;
}