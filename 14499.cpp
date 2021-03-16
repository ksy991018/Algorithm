#include <iostream>
using namespace std;

int N, M, K;
int dx[4] = {0,0,-1,1 }; //동 서 북 남 
int dy[4] = {1,-1,0,0 };
int curX, curY; //현재 위치
int map[21][21];
int dice[6]; //주사위칸에 적혀있는 수 

void calc() {
	if (map[curX][curY] == 0) {
		map[curX][curY] = dice[5]; //주사위 바닥->지도
	}
	else {
		dice[5] = map[curX][curY]; //지도 -> 주사위 바닥
		map[curX][curY] = 0;
	}
}

int main() {
	cin >> N >> M >> curX >> curY >> K;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++){
		int n;
		cin >> n;
		int tmpX = curX + dx[n-1];
		int tmpY = curY + dy[n-1];
		if (tmpX < 0 || tmpX >= N || tmpY < 0 || tmpY >= M) continue; //지도벗어나면 출력x
		 
		curX = tmpX;
		curY = tmpY;
		int tmp[6];
		for (int j = 0; j < 6; j++) {
			tmp[j] = dice[j]; //현재 숫자
		}
		if (n == 3) {//직접 계산 
			dice[0] = tmp[4];
			dice[1] = tmp[0];
			dice[5] = tmp[1];
			dice[4] = tmp[5];
		}
		else if (n == 4) {
			dice[4] = tmp[0];
			dice[0] = tmp[1];
			dice[5] = tmp[4];
			dice[1] = tmp[5];
		}
		else if (n == 2) {
			dice[3] = tmp[0];
			dice[0] = tmp[2];
			dice[2] = tmp[5];
			dice[5] = tmp[3];
		}
		else if(n==1){
			dice[3] = tmp[5];
			dice[0] = tmp[3];
			dice[2] = tmp[0];
			dice[5] = tmp[2];
		}
		calc();
		cout << dice[0] << "\n";	
	}
}

