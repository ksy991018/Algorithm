#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int maze[101][101];
int c[101][101];
int cnt[101][101];

bool check(int x, int y) {
	if (x<1 || x>N || y<1 || y > M) return false; //미로 밖
	if (!maze[x][y]) return false; //미로 막힘
	if (c[x][y]) return false; //이미 방문
	return true;
}

int bfs(pair<int, int> start) {
	queue<pair<int, int>> q;
	q.push(start);
	c[start.first][start.second] = 1;
	cnt[start.first][start.second] = 1;
	while (!q.empty()) {
		
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int tmp = cnt[x][y];
		//상
		if (check(x - 1, y)) {
			q.push(make_pair(x - 1, y));
			c[x - 1][y] = 1;
			cnt[x- 1][y]= tmp+1;
		}
		//하
		if (check(x + 1, y)) {
			q.push(make_pair(x + 1, y));
			c[x + 1][y] = 1;
			cnt[x + 1][y] = tmp + 1;
		}
		//좌
		if (check(x, y - 1)) {
			q.push(make_pair(x, y -1));
			c[x][y-1] = 1;
			cnt[x][y - 1] = tmp + 1;
		}
		//우
		if (check(x, y + 1)) {
			q.push(make_pair(x, y + 1));
			c[x][y + 1] = 1;
			cnt[x][y + 1] = tmp + 1;
		}
	}
	return cnt[N][M];
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}

	cout << bfs(make_pair(1, 1));
}