#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C, T;
int map[50][50];
vector<int> cleaner; //공기청정기 x좌표
queue<pair<pair<int, int>,int>> dust; //<<좌표>,미세먼지양>
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int sum; //출력

bool isInside(int x, int y) {
	if (x >= 0 && x < R && y >= 0 && y < C) return true;
	return false;
}

int bfs() {
	int time = 0; //현재초
	while (time < T) {
		time++;
		int size = dust.size();
		
		for (int i = 0; i < size; i++){
			int x = dust.front().first.first;
			int y = dust.front().first.second;
			int amount = dust.front().second;
			int spread = amount / 5; //퍼질 양
			dust.pop();

			int cnt = 0; //퍼지는 공간수
			for (int j = 0; j < 4; j++){
				int cx = x + dx[j];
				int cy = y + dy[j];
				if (isInside(cx, cy) && map[cx][cy]!=-1) {
					cnt++;
					map[cx][cy] += spread;
				}
			}
			map[x][y]-=spread * cnt; //남은 미세먼지양
		}
		for (int i = 0; i < 2; i++){ //공기청정기 2개
			int preX = (i==0? cleaner[i]-1: cleaner[i]+1); //바람의 역순으로 시작
			int preY = 0;
			for (int j = 0; j < 4; j++){
				while (true) {//첫번째 dx는 {-1,0,1,0} 두번째 dx는 {1,0,-1,0} dy는 동일
					int curX = ((i==1 && j%2==0)? preX+dx[abs(j-2)] : preX + dx[j]); 
					int curY = preY + dy[j];
					if (map[curX][curY] == -1) {//공기청정기면 멈춤
						map[preX][preY] = 0; //공기청정기 시작점은 무조건 0
						break;
					}
					if ((i == 0 && curX > cleaner[i]) || (i == 1 && curX < cleaner[i])||!isInside(curX,curY)) break; // i따라 조건다름
					map[preX][preY] = map[curX][curY]; //바람따라 움직임
					preX = curX;
					preY = curY;		
				}

			}
		}
		sum = 0; //남아있는 미세먼지양 
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j]>0) {
					dust.push({ {i,j},map[i][j] });
					sum += map[i][j]; 
				}
			}
		}
	}
	return sum;
}
int main() {
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) cleaner.push_back(i); //공기청정기
			else if (map[i][j] > 0) dust.push({ {i,j},map[i][j] }); //미세먼지
		}
	}
	cout<< bfs() << endl;
}