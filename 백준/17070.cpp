#include <iostream>
using namespace std;

int N;
int map[17][17];
int dx[3] = { 0,1,1 }; 
int dy[3] = { 1,0,1 };
int cnt;

void dfs(int x, int y, int dir) { //dir : 0(가로),1(세로),2(대각선)
	if (x == N && y == N) {
		cnt++;
		return;
	}

	for (int i = 0; i < 3; i++){ //가로,세로,대각선
		int cx = x + dx[i];
		int cy = y + dy[i];
		if((dir==0 && i==1) || (dir==1 && i==0)) continue; //가로방향이면 세로x , 세로방향이면 가로x

		if (cx >= 1 && cx <= N && cy >= 1 && cy <= N && !map[cx][cy]) {
			if (i == 2 && (map[cx][cy - 1] || map[cx - 1][cy])) continue; //대각선=> 빈공간확인
			dfs(cx, cy, i);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	dfs(1, 2,0); //끝노드 기준
	cout << cnt;
}