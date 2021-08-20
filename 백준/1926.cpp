#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int map[500][500];
int visit[500][500];
int cnt;
int tmpSize, largest; //�׸��� ����
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void solve(int x, int y) {
	visit[x][y] = 1;
	tmpSize++; //�׸��� ����

	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx >= 0 && cx < N && cy >= 0 && cy < M && !visit[cx][cy] && map[cx][cy]) {
			solve(cx, cy);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] && !visit[i][j]) {
				cnt++; //�׸� ����
				tmpSize = 0; //�׸��� ����
				solve(i, j);
				largest = max(tmpSize, largest); //���� ū ����
			}
		}
	}
	cout << cnt << endl;
	cout << largest << endl;
}