#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C, T;
int map[50][50];
vector<int> cleaner; //����û���� x��ǥ
queue<pair<pair<int, int>,int>> dust; //<<��ǥ>,�̼�������>
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int sum; //���

bool isInside(int x, int y) {
	if (x >= 0 && x < R && y >= 0 && y < C) return true;
	return false;
}

int bfs() {
	int time = 0; //������
	while (time < T) {
		time++;
		int size = dust.size();
		
		for (int i = 0; i < size; i++){
			int x = dust.front().first.first;
			int y = dust.front().first.second;
			int amount = dust.front().second;
			int spread = amount / 5; //���� ��
			dust.pop();

			int cnt = 0; //������ ������
			for (int j = 0; j < 4; j++){
				int cx = x + dx[j];
				int cy = y + dy[j];
				if (isInside(cx, cy) && map[cx][cy]!=-1) {
					cnt++;
					map[cx][cy] += spread;
				}
			}
			map[x][y]-=spread * cnt; //���� �̼�������
		}
		for (int i = 0; i < 2; i++){ //����û���� 2��
			int preX = (i==0? cleaner[i]-1: cleaner[i]+1); //�ٶ��� �������� ����
			int preY = 0;
			for (int j = 0; j < 4; j++){
				while (true) {//ù��° dx�� {-1,0,1,0} �ι�° dx�� {1,0,-1,0} dy�� ����
					int curX = ((i==1 && j%2==0)? preX+dx[abs(j-2)] : preX + dx[j]); 
					int curY = preY + dy[j];
					if (map[curX][curY] == -1) {//����û����� ����
						map[preX][preY] = 0; //����û���� �������� ������ 0
						break;
					}
					if ((i == 0 && curX > cleaner[i]) || (i == 1 && curX < cleaner[i])||!isInside(curX,curY)) break; // i���� ���Ǵٸ�
					map[preX][preY] = map[curX][curY]; //�ٶ����� ������
					preX = curX;
					preY = curY;		
				}

			}
		}
		sum = 0; //�����ִ� �̼������� 
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
			if (map[i][j] == -1) cleaner.push_back(i); //����û����
			else if (map[i][j] > 0) dust.push({ {i,j},map[i][j] }); //�̼�����
		}
	}
	cout<< bfs() << endl;
}