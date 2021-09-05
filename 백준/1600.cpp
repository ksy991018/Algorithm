#include <iostream>
#include <queue>
using namespace std;

int K, W, H;
int map[200][200];
int visit[200][200][30]; //����Ʈ �̵������� ����
int dx[12] = { 0,0,1,-1 ,-2,-1,1,2,2,1,-1,-2}; //�����¿� + ����Ʈ �̵�
int dy[12] = { 1,-1,0,0,-1,-2,-2,-1,1,2,2,1 };
int turn = -1; //���� ��

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0,0},0 });
	visit[0][0][0] = 1;
	while (!q.empty()) {
		turn++; //�� ���� 
		int size = q.size();
		while (size--) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int use = q.front().second;
			q.pop();
			if (x == W - 1 && y == H - 1) return turn; //�������� ���¼��� ����
			for (int i = 0; i < 12; i++) {
				if (i == 4 && use == K) break;
				int cx = x + dx[i];
				int cy = y + dy[i];
				if (cx >= 0 && cx < W && cy >= 0 && cy < H && !map[cx][cy]) {
					if (i > 3 && !visit[cx][cy][use + 1]) { //����Ʈ�̵� & �湮üũ
						q.push({ {cx,cy},use + 1 }); //����Ʈ �̵�
						visit[cx][cy][use + 1] = 1;
					}
					else if(i<=3 && !visit[cx][cy][use]) { //�����¿� & �湮üũ
						q.push({ { cx,cy }, use });
						visit[cx][cy][use] = 1;
					}	
				}
			}
		}	
	}
	return -1; //��� Ž������ ������ �������
}

int main() {
	cin >> K >> H >> W;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			cin >> map[i][j];
		}
	}
	cout << bfs() << endl;
}