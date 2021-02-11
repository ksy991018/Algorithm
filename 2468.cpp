#include<iostream>
#include <queue>
#include<cstring>
#include <vector>
using namespace std;

//���̵�� : ���� ���� �־�������, ���� �纸�� ū ���� ���� ������ no_sink�� ǥ�����ְ� 
//no_sink�� �߿� �������ִ� �͵��� 1���� ��. �����Ȱ� ���� �ڱ�ȥ�ڶ�� ����ü�� 1��.

int N;
int map[100][100];
int no_sink[100][100]; //���� ���� �־������� �����°��� 1�� ǥ��
int visit[100][100]; //�湮�ߴ���
int max_depth; //�ִ� ���Ǿ� �����ϱ� ���� ���� ū ���� ����
int protect[101]; //�ε���:���� �� & �� : ��������
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int result; //��� : protect���� ���� ū��

bool is_inside(int x, int y) {
	if (0 <= x && x < N && 0 <= y && y < N) return true;
	return false;
}

bool bfs(int x,int y) { //�湮ǥ�ð� �ٽ�
	if (visit[x][y]) return false;
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (is_inside(cx, cy)&& !visit[cx][cy] && no_sink[cx][cy]) { //���� && �湮x && ����� ����
				visit[cx][cy] = 1;
				q.push({ cx,cy });
			}
		}
	}
	return true;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (max_depth < map[i][j]) max_depth = map[i][j]; //���� ū���� ����
		}
	}

	for (int i = 0; i <= max_depth; i++){//���� ���� ��
		memset(no_sink, 0, sizeof(no_sink)); //���� �翡 ���� ������̽� ����ϱ� ����
		memset(visit, 0, sizeof(visit));
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (map[j][k] > i) no_sink[j][k] = 1; //���� �纸�� ���̳����� ����� ǥ��
				
			}
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (no_sink[j][k]) { //������ ��츸 Ž��
					if (bfs(j, k)) protect[i]++; //bfs�� ���̸� �������� ����
				}
			}
		}
		if (result < protect[i]) result = protect[i]; //protect�� ���� ū�� �������
	}
	cout << result;
}