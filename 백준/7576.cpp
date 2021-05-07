#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int map[1000][1000];
int check[1000][1000]; //�丶�� ���� ��¥
queue<pair<int, int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cnt;

int bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++){
			int cx = x + dx[i];
			int cy = y + dy[i];
			//����Ʈ
			int tmp = check[x][y]; 
			if (cx >= 0 && cx <= N-1 && cy >= 0 && cy <= M-1) {
				if (map[cx][cy] == 0) {
					map[cx][cy] = 1;
					q.push(make_pair(cx, cy)); //���� �丶�� ����
					check[cx][cy] = tmp + 1; //���� ��¥ +1���ֱ�
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] > cnt) cnt = check[i][j]; //���� ��¥�� maxã��
			if (map[i][j] == 0) return -1; //�������丶�� ������ �ٷ� out
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push(make_pair(i, j)); //���� �丶�� ����
				check[i][j] = 0; //ó���̴ϱ� 0
			}
		}
	}
	cout << bfs();
}