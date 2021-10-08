#include <iostream>
#include <algorithm>
using namespace std;

int N, M,K;
int map[101][101];
int visit[101][101];
int result;
int cnt;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y) {
	if (visit[x][y]) return;

	visit[x][y] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx >= 1 && cx <= N && cy >= 1 && cy <= M && map[cx][cy]) dfs(cx, cy);
	}
}

int main() {
	cin >> N >> M >> K;
	while (K--) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] && !visit[i][j]) {
				cnt = 0;
				dfs(i, j);
				result = max(result, cnt);
			}
		}
	}
	cout << result << endl;
}