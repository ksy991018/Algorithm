#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int map[5][5];  //����� ��ȣ
int direction;
int result; //���
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

struct FISH {
	int x;
	int y;
	int dir;
	bool live; 
};
FISH fish[17]; //����� ����

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
void moveFish() { //����� ���ʴ�� ��ĭ�� �̵�
	for (int i = 1; i <= 16; i++) {
		if (fish[i].live) {
			int x = fish[i].x;
			int y = fish[i].y;
			int dir = fish[i].dir - 1;
			for (int j = dir; j < dir + 8; j++) { //��ĭ �̵��Ҷ�����. ������ �̵����ϸ� ������
				j %= 8;
				int cx = x + dx[j];
				int cy = y + dy[j];
				if (cx >= 1 && cx <= 4 && cy >= 1 && cy <= 4 && map[cx][cy]!=-1) { //����ڸ� �ƴϸ�
					int nextFish = map[cx][cy];
					if (nextFish != 0) { //���ڸ� �ƴѰ�� ����ⱳȯ.
						fish[nextFish].x = x;
						fish[nextFish].y = y;
					}
					fish[i].x = cx;
					fish[i].y = cy;
					map[cx][cy] = i;
					map[x][y] = nextFish;
					fish[i].dir = j+1;
					break; //��ĭ���� �̵�����
				}
			}
		}
	}
}

void dfs(int x, int y, int dir, int sum) {
	result = max(result, sum); //����� ��ȣ�� �ִ� ��
	FISH tempFish[17];
	int map_cp[5][5];
	make_cp(tempFish, fish, map_cp, map); //����� ��ġ,���� �ӽ�����
	moveFish(); //����� �̵�

	for (int i = 1; i <= 3; i++) { //��� �ش�������� �ִ� 3ĭ �̵�����
		int cx = x + dx[dir - 1] * i; 
		int cy = y + dy[dir - 1] * i;
		if (1 <= cx && cx <= 4 && 1 <= cy && cy <= 4) {
			if (map[cx][cy] == 0) continue; //����ִ�ĭ pass
			int fishNum = map[cx][cy];  //��� �̵�
			map[cx][cy] = -1;
			fish[fishNum].live = false;
			map[x][y] = 0;
			dfs(cx, cy, fish[fishNum].dir, sum + fishNum); //��Ʈ��ŷ
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
	int firstFish = map[1][1]; //���۹����
	int sharkDir = fish[map[1][1]].dir; //���۹���� ����
	fish[map[1][1]].live = false; //���۹���� ����
	map[1][1] = -1; //�����ġ ǥ��
	dfs(1, 1, sharkDir, firstFish);
	cout << result;
}