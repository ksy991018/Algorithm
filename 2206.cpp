#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int map[1001][1001];
int visit[1001][1001][2]; //������ �ε��� : �� �νǼ��ִ� Ƚ��, visit:���° �̵�����
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

//�ٽ� : �� �νð� ���� ���, �ƴ� ��� �Ѵ� ���
//visit 2�����迭 -> ���νð� �� ��ο� �Ⱥνð� �� ��ΰ� ���� ��忡�� ������ ��������
//visit 3���� �迭 -> �� �ΰ��� ��� ���� �湮 üũ����

bool is_inside(int x, int y) {
	if (x >= 1 && x <= N && y >= 1 && y <= M) return true;
	return false;
}

int bfs() {
	queue<pair<pair<int, int>,int>> q; 
	q.push({ { 1,1 },1 }); //�� �νǱ�ȸ : 1
	visit[1][1][1] = 1; //�̵� 1���� ����
	visit[1][1][0] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int block = q.front().second;
		q.pop();

		int tmp = visit[x][y][block]; //���� �����̵�
		if (x == N && y == M) return tmp;
		for (int i = 0; i < 4; i++) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (is_inside(cx,cy)) {
				if (block && map[cx][cy]) { //���̰� �νǱ�ȸ ������ 
					visit[cx][cy][block - 1] = tmp + 1; //�νð� ��ȸ -1, �̵�+1
					q.push({ {cx,cy},block - 1 });
				}
				if (!map[cx][cy] && !visit[cx][cy][block]) { //���ƴϰ� �湮���� ������ 
					visit[cx][cy][block] = tmp + 1; //��ȸ ����, �̵�+1
					q.push({ {cx,cy},block });
				}
			}
		}
	}
	return 0; //�� ������������
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	int result = bfs();
	cout << (result!= 0 ? result : -1);
}

