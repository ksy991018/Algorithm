#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[101][101]; 
int visit[101][101];
int outerair[101][101];  //바깥쪽 공기표시 
int cnt; //남아있는 치즈수
int time;
int latest; //가장 최근 치즈수
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

//핵심 : 닫힌구멍, 열린구멍 따로 구별할 필요없음. (0,0)부터 bfs돌려서 이어진부분과 접해있는 치즈만 열린구멍

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j]) cnt++; //치즈수
		}
	}

	while (cnt > 0) {
		memset(visit, 0, sizeof(visit));
		time++;
		queue<pair<int, int>> air; //치즈 바깥공기
		air.push({ 0,0 });
		visit[0][0] = 1;
		while (!air.empty()) { //바깥쪽 공기 (치즈영향주는 공기) bfs
			int x = air.front().first;
			int y = air.front().second;
			air.pop();
			outerair[x][y] = 1;
			
			for (int i = 0; i < 4; i++){
				int cx = x+dx[i];
				int cy = y+dy[i];
				if (cx >= 0 && cx < N && cy >= 0 && cy < M && !visit[cx][cy] && map[cx][cy] == 0) {
					visit[cx][cy] = 1;
					air.push({ cx,cy });
				}
			}
		}
		vector<pair<int, int>> cheese; //바깥공기 닿는 치즈
		latest = 0; //현재 상태에서의 치즈갯수

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					for (int k = 0; k < 4; k++) {
						int x = i + dx[k];
						int y = j + dy[k];
						if (x>=0 && x<N && y>=0 && y<M && outerair[x][y]) { //현재 위치와 인접한곳에 바깥공기 존재할 경우 열린구멍임
							cnt--; //전체 치즈수 감소
							latest++; //현재 turn에서의 치즈수 증가
							map[i][j] = 0; //치즈 사라짐
							break;
						}
					}
				}
			}
		}
	}

	cout << time << endl << latest << endl;
}