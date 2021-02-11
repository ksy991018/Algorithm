#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int M, N, H; //����,����,����
int map[100][100][100];
int check[100][100][100]; //�丶�� ���� ��¥ ����. visit & count ��� check���� �ϳ��� �ذ�
int dx[6] = { 1,-1,0,0,0,0 };//�����¿����Ʒ�
int dy[6] = { 0,0,1,-1,0,0 };
int dh[6] = { 0,0,0,0,1,-1 };
queue<pair<pair<int, int>, int>> q; //���� �丶����� ť. {{x,y},h}

bool is_inside(int h, int x, int y) {
	if (0 <= h && h < H && x >= 0 && x < N && y >= 0 && y < M) return true;
	return false;
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int h = q.front().second;
		q.pop();
		int tmp = check[h][x][y]; //���� ��ġ���� ������¥
		for (int i = 0; i < 6; i++){
			int cx = x + dx[i];
			int cy = y + dy[i];
			int ch = h + dh[i];
			if (is_inside(ch, cx, cy) && map[ch][cx][cy]==0) { //�丶�� ���Ͱ�, �������� ������
				map[ch][cx][cy] = 1; //������
				check[ch][cx][cy] = tmp+1; //���� �丶�� ������¥+1
				q.push({ { cx,cy }, ch });
			}
		}
	}
}

int main() {
	cin >> M >> N >> H;
	bool all_done = true; //ó������ �� �;��ִ��� Ȯ��

	for (int i = 0; i < H; i++){
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push({ {j,k} , i }); //���� �丶�� �ֱ�
				}
				if (map[i][j][k] == 0) {
					all_done = false;
				}
			}
		}
	}
	if (all_done) cout << 0; //�ѹ��� ������ �丶��ȳ�����
	else {
		bfs();
		bool flag = true; //bfs������ ������ �丶�� �ִ��� Ȯ��
		int result = 0; //���� �������� ������¥ 
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					if (check[i][j][k] > result) result = check[i][j][k];
					if (map[i][j][k] == 0) { //�������� �������
						flag = false;
						break;
					}
				}
			}
		}
		cout << (flag ? result : -1); //�������� ������ -1
	}
}