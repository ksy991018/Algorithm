#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[101][101]; 
int visit[101][101];
int outerair[101][101];  //�ٱ��� ����ǥ�� 
int cnt; //�����ִ� ġ���
int time;
int latest; //���� �ֱ� ġ���
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

//�ٽ� : ��������, �������� ���� ������ �ʿ����. (0,0)���� bfs������ �̾����κа� �����ִ� ġ� ��������

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j]) cnt++; //ġ���
		}
	}

	while (cnt > 0) {
		memset(visit, 0, sizeof(visit));
		time++;
		queue<pair<int, int>> air; //ġ�� �ٱ�����
		air.push({ 0,0 });
		visit[0][0] = 1;
		while (!air.empty()) { //�ٱ��� ���� (ġ����ִ� ����) bfs
			int x = air.front().first;
			int y = air.front().second;
			air.pop();
			outerair[x][y] = 1;
			
			for (int i = 0; i < 4; i++){
				int cx = x+dx[i];
				int cy = y+dy[i];
				if (cx >= 0 && cx < N && cy >= 0 && cy < M && !visit[cx][cy] && map[cx][cy] == 0) {
					visit[cx][cy] = 1;
					air.push({ cx,cy });
				}
			}
		}
		vector<pair<int, int>> cheese; //�ٱ����� ��� ġ��
		latest = 0; //���� ���¿����� ġ���

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					for (int k = 0; k < 4; k++) {
						int x = i + dx[k];
						int y = j + dy[k];
						if (x>=0 && x<N && y>=0 && y<M && outerair[x][y]) { //���� ��ġ�� �����Ѱ��� �ٱ����� ������ ��� ����������
							cnt--; //��ü ġ��� ����
							latest++; //���� turn������ ġ��� ����
							map[i][j] = 0; //ġ�� �����
							break;
						}
					}
				}
			}
		}
	}

	cout << time << endl << latest << endl;
}