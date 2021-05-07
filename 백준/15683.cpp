#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int n;
int map[8][8];
vector<pair<int, int>> cameraPos; //cctv좌표
vector<int> camera; //cctv 종류
int result=1000000;

void check(int pos, int x, int y) { //cctv감시영역 표시
	if (pos == 0) {//동
		if (map[x][y + 1]!=6 && y+1<M) {
			map[x][y + 1] = -1;
			check(pos, x, y + 1);
		}
	}
	else if (pos == 1) {//북
		if (map[x-1][y] != 6 && x-1 >= 0) {
			map[x-1][y] = -1;
			check(pos, x-1, y);
		}
	}
	else if (pos == 2) {//서
		if (map[x][y - 1] != 6 && y - 1 >=0) {
			map[x][y - 1] = -1;
			check(pos, x, y - 1);
		}
	}
	else if (pos == 3) {//남
		if (map[x+1][y] != 6 && x + 1 < N) {
			map[x+1][y] = -1;
			check(pos, x+1, y);
		}
	}
}
void copyMap(int a[8][8], int b[8][8]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void dfs(int cnt) {
	if (cnt == camera.size()) { //모든 cctv체크하면
		int tmp = 0;
		for (int i = 0; i < N; i++) { //사각지대
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0) tmp++;
			}
		}
		if (result > tmp) result = tmp;
		return;
	}
	int choice = camera[cnt];
	int x = cameraPos[cnt].first;
	int y = cameraPos[cnt].second;
	int map_cp[8][8]; //현재 상태 복원
	
	if (choice == 1) {
		for (int i = 0; i < 4; i++){ 
			copyMap(map_cp, map); 
			check(i, x, y);
			dfs(cnt + 1);
			copyMap(map, map_cp);
		}
	}else if (choice == 2) {
		for (int i = 0; i < 2; i++) {
			copyMap(map_cp, map);
			check(i, x, y);
			check(i + 2,x,y);
			dfs(cnt + 1);
			copyMap(map, map_cp);
		}
	}else if (choice == 3) {
		for (int i = 0; i < 4; i++) {
			copyMap(map_cp, map);
			check(i, x, y);
			check((i + 1)%4, x, y);
			dfs(cnt + 1);
			copyMap(map, map_cp);
		}
	}else if (choice == 4) {
		for (int i = 0; i < 4; i++) {
			copyMap(map_cp, map);
			check(i, x, y);
			check((i+1)%4, x, y);
			check((i+2)%4, x, y);
			dfs(cnt + 1);
			copyMap(map, map_cp);
		}
	}else if (choice == 5) {
		for (int i = 0; i < 4; i++) {
			copyMap(map_cp, map);
			check(i, x, y);
		}
		dfs(cnt + 1);
		copyMap(map, map_cp);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6) {
				cameraPos.push_back({ i,j });
				camera.push_back(map[i][j]);
			}
		}
	}
	dfs(0);

	cout << result;

}