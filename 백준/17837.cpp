#include <iostream>
#include <queue>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
int map[12][12];
deque<int> horse[12][12]; //좌표마다 쌓여있는 말들의 번호 높이순 저장
vector<pair<pair<int, int>,int>> v; // 말들의 정보 저장, 인덱스 : 말번호, 값 : <<x,y>,방향>
int turn;

int main() {
	cin >> N >> K;
	for (int i = 0; i < N ; i++){
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int x, y, dir;
	for (int i = 0; i < K; i++){
		cin >> x >> y >> dir;
		horse[x - 1][y - 1].push_back(i);
		v.push_back({ {x-1,y-1},dir });
	}
	bool exit = false; //말 4개이상 여부
	while (!exit && turn <= 1000) {
		turn++; //턴 증가
		for (int i = 0; i < K; i++){//모든 말에 대해 실행
			int x = v[i].first.first;
			int y = v[i].first.second;
			int dir = v[i].second;
			int cx = x + dx[dir];
			int cy = y + dy[dir];
			if (cx < 0 || cx >= N || cy < 0 || cy >= N || map[cx][cy]==2) {//범위밖 or 파랑 -> 방향바꾸기
				if (dir == 1) dir = 2;
				else if (dir == 2) dir = 1;
				else if (dir == 3) dir = 4;
				else dir = 3;
				cx = x + dx[dir];
				cy = y + dy[dir];
				v[i].second = dir; //방향 바꾸기
			}
			if (cx >= 0 && cx < N && cy >= 0 && cy < N) { //범위 안
				if (map[cx][cy] == 0 || map[cx][cy]==1) {//흰색 or 빨간색 , 파란색인 경우 아무것도 안함
					vector<int> tmphorse; //임시 저장 <- reverse사용 위해 따로 선언
					int size = horse[x][y].size();
					bool flag = false; //같이 옮길 말들인지 여부
					for (int j = 0; j < size; j++) {//해당 말부터 위에있는거까지 모두 옮기기
						int tmp = horse[x][y][0]; //현재 탐색할 말
						horse[x][y].pop_front();
						if (flag || tmp == i) {//해당말이거나 해당말 위에있으면 옮기기
							flag = true; 					
							tmphorse.push_back(tmp);
							v[tmp].first.first = cx;
							v[tmp].first.second = cy; //말 위치정보 업데이트
						}else {					
							horse[x][y].push_back(tmp); //안옮기면 원래좌표에 다시넣기
						}
					}
					if (map[cx][cy] == 1) reverse(tmphorse.begin(), tmphorse.end()); //빨강이면 순서반대로
					for (int k = 0; k < tmphorse.size(); k++){ //최종적으로 옮기기
						horse[cx][cy].push_back(tmphorse[k]);
					}
					if (horse[cx][cy].size() >= 4) {//4개이상 쌓이면
						exit = true;
						break;
					}
				}
			}
		}

	}
	cout << (turn>1000? -1 : turn) << endl;
}