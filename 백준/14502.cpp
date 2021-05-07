#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int map[8][8];
int map_cp[8][8];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int N, M;
int ans=0;
vector <pair<int, int>> virus;

//���̷��� �۶߸�
void bfs() {
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++){
		q.push(make_pair(virus[i].first, virus[i].second));
	}


	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++){
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx >= 0 && cx <= N-1 && cy >= 0 && cy <= M-1) {
				if (!map_cp[cx][cy]) {
					map_cp[cx][cy] = 2;
					q.push(make_pair(cx, cy));
					
				}
			}
		}
	}

	//�������� �˻�
	int tmp = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			if (map_cp[i][j] == 0) {
				tmp++;
			}
		}
	}
	ans = max(ans, tmp);
	
}

//�� 3�� �����
void makewall(int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++) {
				map_cp[i][j] = map[i][j]; //���� map �״�� �ӽú���
			}
		}
		bfs(); //map_cp������ ���̷��� �۶߸�
		return;
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) { //��ĭ�̸� ����
				map[i][j] = 1; 
				makewall(cnt + 1);
				map[i][j] = 0; //����
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) virus.push_back(make_pair(i, j));
			//���̷��� ���� ����
		}
	}

	//�� ������ִ� ����� �õ�
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				makewall(1);
				map[i][j] = 0;
			}
		}
	}

	cout << ans;

	return 0;
}