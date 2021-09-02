#include <iostream>
using namespace std;

int N, M, K;
int dx[2] = { 0,-1 };//뒤,위
int dy[2] = { -1,0 };
int map[16][16];
int absX, absY;

bool check(int x, int y) {
	if (x > absX && y < absY) return false; //O기준 왼쪽밑
	else if (x<absX && y>absY) return false; //O기준 오른쪽위
	else return true;
}

int main() {
	cin >> N >> M >> K;
	if (K != 0) { //꼭 지나가야 하는곳의 좌표
		absX = (K % M == 0 ? K / M : K / M + 1); 
		absY = (K % M == 0 ? M : K % M);
	}
	map[1][1] = 1;
	for (int i = 1; i <=N ; i++){
		for (int j = 1; j <= M; j++) {
			if (i == 1 && j == 1) continue;
			if (K!=0 && !check(i, j)) continue; //거리 정보 사용여부
			for (int k = 0; k < 2; k++){ 
				int cx = i + dx[k];
				int cy = j + dy[k];
				if (cx >= 1 && cx <= N && cy >= 1 && cy <= M) map[i][j] += map[cx][cy]; //경우의 수 누적
			}
		}
	}
	cout << map[N][M]<<endl;
}