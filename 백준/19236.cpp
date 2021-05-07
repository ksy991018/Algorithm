#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int map[5][5];  //물고기 번호
int direction;
int result; //출력
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

struct FISH {
	int x;
	int y;
	int dir;
	bool live; 
};
FISH fish[17]; //물고기 저장

void make_cp(FISH tempFish[17], FISH fish[17], int map_cp[5][5], int map[5][5]) {
	for (int i = 1; i <= 16; i++) {
		tempFish[i] = fish[i];
	}
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			map_cp[i][j] = map[i][j];
		}
	}
}
void moveFish() { //물고기 차례대로 한칸씩 이동
	for (int i = 1; i <= 16; i++) {
		if (fish[i].live) {
			int x = fish[i].x;
			int y = fish[i].y;
			int dir = fish[i].dir - 1;
			for (int j = dir; j < dir + 8; j++) { //한칸 이동할때까지. 끝까지 이동못하면 가만히
				j %= 8;
				int cx = x + dx[j];
				int cy = y + dy[j];
				if (cx >= 1 && cx <= 4 && cy >= 1 && cy <= 4 && map[cx][cy]!=-1) { //상어자리 아니면
					int nextFish = map[cx][cy];
					if (nextFish != 0) { //빈자리 아닌경우 물고기교환.
						fish[nextFish].x = x;
						fish[nextFish].y = y;
					}
					fish[i].x = cx;
					fish[i].y = cy;
					map[cx][cy] = i;
					map[x][y] = nextFish;
					fish[i].dir = j+1;
					break; //한칸씩만 이동위해
				}
			}
		}
	}
}

void dfs(int x, int y, int dir, int sum) {
	result = max(result, sum); //물고기 번호의 최대 합
	FISH tempFish[17];
	int map_cp[5][5];
	make_cp(tempFish, fish, map_cp, map); //물고기 위치,정보 임시저장
	moveFish(); //물고기 이동

	for (int i = 1; i <= 3; i++) { //상어 해당방향으로 최대 3칸 이동가능
		int cx = x + dx[dir - 1] * i; 
		int cy = y + dy[dir - 1] * i;
		if (1 <= cx && cx <= 4 && 1 <= cy && cy <= 4) {
			if (map[cx][cy] == 0) continue; //비어있는칸 pass
			int fishNum = map[cx][cy];  //상어 이동
			map[cx][cy] = -1;
			fish[fishNum].live = false;
			map[x][y] = 0;
			dfs(cx, cy, fish[fishNum].dir, sum + fishNum); //백트래킹
			map[cx][cy] = fishNum;
			fish[fishNum].live = true;
			map[x][y] = -1;
		}

	}
	make_cp(fish, tempFish, map, map_cp);
}

int main() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			cin >> map[i][j];
			cin >> direction;
			fish[map[i][j]] = { i,j,direction,true };
		}
	}
	int firstFish = map[1][1]; //시작물고기
	int sharkDir = fish[map[1][1]].dir; //시작물고기 방향
	fish[map[1][1]].live = false; //시작물고기 죽음
	map[1][1] = -1; //상어위치 표시
	dfs(1, 1, sharkDir, firstFish);
	cout << result;
}