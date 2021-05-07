#include <iostream>
using namespace std;

int N;
int map[17][17];
int dx[3] = { 0,1,1 }; 
int dy[3] = { 1,0,1 };
int cnt;

void dfs(int x, int y, int dir) { //dir : 0(����),1(����),2(�밢��)
	if (x == N && y == N) {
		cnt++;
		return;
	}

	for (int i = 0; i < 3; i++){ //����,����,�밢��
		int cx = x + dx[i];
		int cy = y + dy[i];
		if((dir==0 && i==1) || (dir==1 && i==0)) continue; //���ι����̸� ����x , ���ι����̸� ����x

		if (cx >= 1 && cx <= N && cy >= 1 && cy <= N && !map[cx][cy]) {
			if (i == 2 && (map[cx][cy - 1] || map[cx - 1][cy])) continue; //�밢��=> �����Ȯ��
			dfs(cx, cy, i);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	dfs(1, 2,0); //����� ����
	cout << cnt;
}