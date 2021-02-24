#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int T;
int N;
int startX, startY;
int endX, endY;
int visit[300][300];
int cnt[300][300];
int dy[8] = { -2,-2,-1,-1,1,1,2,2 };
int dx[8] = { -1,1,-2,2,-2,2,-1,1 };

int bfs() {
	queue<pair<int, int>> q;
	q.push({ startX,startY });
	visit[startX][startY] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		visit[x][y] = 1;
		int tmp = cnt[x][y];
		for (int i = 0; i < 8; i++) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx >= 0 && cx < N && cy >= 0 && cy < N && !visit[cx][cy]) {
				visit[cx][cy] = 1;
				if (cx == endX && cy == endY) return tmp + 1;
				cnt[cx][cy] = tmp + 1;
				q.push({ cx,cy });
			}
		}

	}
}

int main() {
	cin >> T;

	while (T--) {
		memset(visit, 0, sizeof(visit));
		memset(cnt, 0, sizeof(cnt));
		cin >> N;
		cin >> startX >> startY;
		cin >> endX >> endY;
		cout << (startX==endX && startY==endY? 0:bfs()) << "\n";
	}
}