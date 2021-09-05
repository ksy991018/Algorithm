#include <iostream>
#include <queue>
using namespace std;

int K, W, H;
int map[200][200];
int visit[200][200][30]; //나이트 이동수까지 포함
int dx[12] = { 0,0,1,-1 ,-2,-1,1,2,2,1,-1,-2}; //상하좌우 + 나이트 이동
int dy[12] = { 1,-1,0,0,-1,-2,-2,-1,1,2,2,1 };
int turn = -1; //동작 수

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0,0},0 });
	visit[0][0][0] = 1;
	while (!q.empty()) {
		turn++; //한 동작 
		int size = q.size();
		while (size--) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int use = q.front().second;
			q.pop();
			if (x == W - 1 && y == H - 1) return turn; //도착지점 오는순간 종료
			for (int i = 0; i < 12; i++) {
				if (i == 4 && use == K) break;
				int cx = x + dx[i];
				int cy = y + dy[i];
				if (cx >= 0 && cx < W && cy >= 0 && cy < H && !map[cx][cy]) {
					if (i > 3 && !visit[cx][cy][use + 1]) { //나이트이동 & 방문체크
						q.push({ {cx,cy},use + 1 }); //나이트 이동
						visit[cx][cy][use + 1] = 1;
					}
					else if(i<=3 && !visit[cx][cy][use]) { //상하좌우 & 방문체크
						q.push({ { cx,cy }, use });
						visit[cx][cy][use] = 1;
					}	
				}
			}
		}	
	}
	return -1; //모든 탐색동안 도착점 못간경우
}

int main() {
	cin >> K >> H >> W;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			cin >> map[i][j];
		}
	}
	cout << bfs() << endl;
}