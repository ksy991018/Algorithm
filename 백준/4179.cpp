#include <iostream>
#include <queue>
using namespace std;

int R, C;
char maps[1000][1000];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int visit[1000][1000];
queue <pair<int, int>> fire;
queue <pair<int, int>> jihoon;

int bfs() {
	int cnt = 0;
	while (!jihoon.empty()) {
		cnt++;
		int size = fire.size();
		while (size--) {//불 이동
			int x = fire.front().first;
			int y = fire.front().second;
			fire.pop();
			for (int i = 0; i < 4; i++) {
				int cx = x + dx[i];
				int cy = y + dy[i];
				if (cx >= 0 && cx < R && cy >= 0 && cy < C && maps[cx][cy] != '#' && maps[cx][cy] != 'F') {
					maps[cx][cy] = 'F';
					fire.push({ cx,cy });
				}
			}
		}
		size = jihoon.size();
		while (size--) {//지훈 이동 
			int x = jihoon.front().first;
			int y = jihoon.front().second;
			jihoon.pop();
			if (x == 0 || x == R - 1 || y == 0 || y == C - 1) return cnt; //가장자리에 있으면 바로 탈출 

			for (int i = 0; i < 4; i++) {
				int cx = x + dx[i];
				int cy = y + dy[i];
				if (cx >= 0 && cx < R && cy >= 0 && cy < C && maps[cx][cy] == '.' && !visit[cx][cy]) {
					visit[cx][cy] = 1;
					jihoon.push({ cx,cy });
				}
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 'F') fire.push({ i,j });
			if (maps[i][j] == 'J') {
				jihoon.push({ i,j });
				visit[i][j] = 1;
			}
		}
	}

	int result = bfs();

	if (result != -1) cout << result << '\n';
	else cout << "IMPOSSIBLE\n";
}