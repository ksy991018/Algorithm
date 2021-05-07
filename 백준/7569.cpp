#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int M, N, H; //세로,가로,높이
int map[100][100][100];
int check[100][100][100]; //토마토 익은 날짜 저장. visit & count 대신 check변수 하나로 해결
int dx[6] = { 1,-1,0,0,0,0 };//상하좌우위아래
int dy[6] = { 0,0,1,-1,0,0 };
int dh[6] = { 0,0,0,0,1,-1 };
queue<pair<pair<int, int>, int>> q; //익은 토마토넣을 큐. {{x,y},h}

bool is_inside(int h, int x, int y) {
	if (0 <= h && h < H && x >= 0 && x < N && y >= 0 && y < M) return true;
	return false;
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int h = q.front().second;
		q.pop();
		int tmp = check[h][x][y]; //현재 위치에서 익은날짜
		for (int i = 0; i < 6; i++){
			int cx = x + dx[i];
			int cy = y + dy[i];
			int ch = h + dh[i];
			if (is_inside(ch, cx, cy) && map[ch][cx][cy]==0) { //토마토 안익고, 범위내에 있으면
				map[ch][cx][cy] = 1; //익히기
				check[ch][cx][cy] = tmp+1; //현재 토마토 익은날짜+1
				q.push({ { cx,cy }, ch });
			}
		}
	}
}

int main() {
	cin >> M >> N >> H;
	bool all_done = true; //처음부터 다 익어있는지 확인

	for (int i = 0; i < H; i++){
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push({ {j,k} , i }); //익은 토마토 넣기
				}
				if (map[i][j][k] == 0) {
					all_done = false;
				}
			}
		}
	}
	if (all_done) cout << 0; //한번도 안익은 토마토안나오면
	else {
		bfs();
		bool flag = true; //bfs돌리고 안익은 토마토 있는지 확인
		int result = 0; //가장 마지막에 익은날짜 
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					if (check[i][j][k] > result) result = check[i][j][k];
					if (map[i][j][k] == 0) { //안익으면 즉시종료
						flag = false;
						break;
					}
				}
			}
		}
		cout << (flag ? result : -1); //안익은거 있으면 -1
	}
}