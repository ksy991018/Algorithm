#include <iostream>
#include <queue>
using namespace std;

int R, C; //��,��
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt[50][50]; //���° ����
char map[50][50]; 
int visit[50][50];
int arriveX, arriveY; //�������ġ
queue<pair<int, int>> water; //���� ��ġ
queue<pair<int, int>> q; //����ġ ��ġ

bool check(int x, int y) {
	if (x >= 0 && x < R && y >= 0 && y < C) return true;
	return false;
}

void bfs() {
	while (!q.empty()) {
		int wsize = water.size(); //����Ʈ: ��Ÿ�ӿ� �� �ѹ��� ��������.
		for (int i = 0; i < wsize; i++){
			int wx = water.front().first;
			int wy = water.front().second;
			water.pop();
			for (int i = 0; i < 4; i++) {
				int cx = wx + dx[i];
				int cy = wy + dy[i];
				if (check(cx, cy) && map[cx][cy] != 'D' && map[cx][cy] != 'X' && map[cx][cy]!='*') {//�����,��,��x
					map[cx][cy] = '*';
					water.push({ cx, cy });
				}
			}
		}
		int qsize = q.size(); // //����Ʈ: ��Ÿ�ӿ� ����ġ ��ĭ �̵�
		for (int i = 0; i < qsize; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			visit[x][y] = 1;
			int tmp = cnt[x][y]; //���� cnt
			for (int i = 0; i < 4; i++) {
				int cx = x + dx[i];
				int cy = y + dy[i];

				if (check(cx, cy) && !visit[cx][cy] && map[cx][cy] != '*' && map[cx][cy] != 'X') {
					visit[cx][cy] = 1;
					cnt[cx][cy] = tmp + 1; //cnt+1
					if (map[cx][cy] == 'D') break; //������̸� �������
					q.push({ cx,cy });
				}
			}
		}
		
	}
}

int main() {
	cin >> R >> C;
	
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'D') { //�����
				arriveX = i;
				arriveY= j;
			}
			if (map[i][j] == 'S') { //����ġ
				q.push({ i,j });
			}
			if (map[i][j] == '*') { //���� ��ġ
				water.push({ i,j });
			}
		}
	}

	bfs();

	if (cnt[arriveX][arriveY] == 0) cout << "KAKTUS";
	else cout << cnt[arriveX][arriveY];
}