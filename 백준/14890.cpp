#include <iostream>
#include <cstring>
using namespace std;

int N, L;
int map[100][100]; 
int map_cp[100][100]; //y=-x대칭
int visit[100]; //경사로 표시
int result; //길의 개수

int solve(int x, int y, int height) {
	if (0 > x || x >= N || y < 0 || y >= N) return 1; //한줄다 지나옴

	if (height == map[x][y]) return solve(x, y + 1, height); 
	else if (height + 1 == map[x][y]) {//현재 높이가 그전 높이보다 한층 높으면
		for (int i = 1; i <= L; i++) { //L번 뒤부터 바로전까지 체크
			if (y - i < 0 || map[x][y - i] != height || visit[y - i]) return 0; //범위, 높이,경사로유무 체크
			visit[y - i] = 1; //경사로세움
		}
		return solve(x, y + 1, height + 1); 
	}
	else if (height - 1 == map[x][y]) {//현재 높이가 그전 높이보다 한층 낮으면
		for (int i = 0; i < L; i++) {//현재 위치부터 L번 앞에까지 체크
			if (y + i >= N || map[x][y + i] != height-1) return 0;
			visit[y + i] = 1;
		}
		return solve(x, y + L, height - 1);
	}
	else return 0; //높이 2이상 차이 
}

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			map_cp[j][i] = map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {//가로줄 탐색
		memset(visit, 0, sizeof(visit));
		if (solve(i, 1, map[i][0])) result++; //인덱스 1부터시작. 높이는 0번인덱스
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) 
			map[i][j] = map_cp[i][j]; //solve함수 그대로 쓰기위해
	}

	for (int i = 0; i < N; i++) { //세로줄 탐색
		memset(visit, 0, sizeof(visit));
		if (solve(i, 1, map[i][0]))result++;		
	}
	cout << result;
}

