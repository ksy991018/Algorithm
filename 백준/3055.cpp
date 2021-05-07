#include <iostream>
#include <queue>
using namespace std;

int R, C; //행,열
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt[50][50]; //몇번째 도착
char map[50][50]; 
int visit[50][50];
int arriveX, arriveY; //비버굴위치
queue<pair<int, int>> water; //물의 위치
queue<pair<int, int>> q; //고슴도치 위치

bool check(int x, int y) {
	if (x >= 0 && x < R && y >= 0 && y < C) return true;
	return false;
}

void bfs() {
	while (!q.empty()) {
		int wsize = water.size(); //포인트: 한타임에 물 한번만 퍼져나감.
		for (int i = 0; i < wsize; i++){
			int wx = water.front().first;
			int wy = water.front().second;
			water.pop();
			for (int i = 0; i < 4; i++) {
				int cx = wx + dx[i];
				int cy = wy + dy[i];
				if (check(cx, cy) && map[cx][cy] != 'D' && map[cx][cy] != 'X' && map[cx][cy]!='*') {//비버굴,돌,물x
					map[cx][cy] = '*';
					water.push({ cx, cy });
				}
			}
		}
		int qsize = q.size(); // //포인트: 한타임에 고슴도치 한칸 이동
		for (int i = 0; i < qsize; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			visit[x][y] = 1;
			int tmp = cnt[x][y]; //현재 cnt
			for (int i = 0; i < 4; i++) {
				int cx = x + dx[i];
				int cy = y + dy[i];

				if (check(cx, cy) && !visit[cx][cy] && map[cx][cy] != '*' && map[cx][cy] != 'X') {
					visit[cx][cy] = 1;
					cnt[cx][cy] = tmp + 1; //cnt+1
					if (map[cx][cy] == 'D') break; //비버굴이면 즉시종료
					q.push({ cx,cy });
				}
			}
		}
		
	}
}

int main() {
	cin >> R >> C;
	
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'D') { //비버굴
				arriveX = i;
				arriveY= j;
			}
			if (map[i][j] == 'S') { //고슴도치
				q.push({ i,j });
			}
			if (map[i][j] == '*') { //물의 위치
				water.push({ i,j });
			}
		}
	}

	bfs();

	if (cnt[arriveX][arriveY] == 0) cout << "KAKTUS";
	else cout << cnt[arriveX][arriveY];
}