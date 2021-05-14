#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int R, C;
char map[250][250];
int visit[250][250];
queue<pair<int,int>> wolf;
int w; int s;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };


void bfs(int x, int y) {
	queue<pair<int,int>> q;
	q.push({ x,y });
	visit[x][y] = 1;
	int tmpw = 1; int tmps = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();	
		for (int i = 0; i < 4; i++){
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx >= 0 && cx < R && cy >= 0 && cy < C && !visit[cx][cy] && map[cx][cy] != '#') {
				visit[cx][cy] = 1;
				if (map[cx][cy] == 'o') tmps++;
				if (map[cx][cy] == 'v') tmpw++;
				q.push({ cx,cy });
			}
		}
	}
	if (tmps > tmpw) w -= tmpw;
	else s -= tmps;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'v') {
				wolf.push({ i,j });
				w++;
			}
			else if (map[i][j] == 'o') s++;
		}
	}

	while (!wolf.empty()) {
		int x = wolf.front().first;
		int y = wolf.front().second;
		wolf.pop();
		if (!visit[x][y]) bfs(x, y);
	}

	cout << s << " " << w;
}