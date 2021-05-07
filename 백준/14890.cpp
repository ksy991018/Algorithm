#include <iostream>
#include <cstring>
using namespace std;

int N, L;
int map[100][100]; 
int map_cp[100][100]; //y=-x��Ī
int visit[100]; //���� ǥ��
int result; //���� ����

int solve(int x, int y, int height) {
	if (0 > x || x >= N || y < 0 || y >= N) return 1; //���ٴ� ������

	if (height == map[x][y]) return solve(x, y + 1, height); 
	else if (height + 1 == map[x][y]) {//���� ���̰� ���� ���̺��� ���� ������
		for (int i = 1; i <= L; i++) { //L�� �ں��� �ٷ������� üũ
			if (y - i < 0 || map[x][y - i] != height || visit[y - i]) return 0; //����, ����,�������� üũ
			visit[y - i] = 1; //���μ���
		}
		return solve(x, y + 1, height + 1); 
	}
	else if (height - 1 == map[x][y]) {//���� ���̰� ���� ���̺��� ���� ������
		for (int i = 0; i < L; i++) {//���� ��ġ���� L�� �տ����� üũ
			if (y + i >= N || map[x][y + i] != height-1) return 0;
			visit[y + i] = 1;
		}
		return solve(x, y + L, height - 1);
	}
	else return 0; //���� 2�̻� ���� 
}

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			map_cp[j][i] = map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {//������ Ž��
		memset(visit, 0, sizeof(visit));
		if (solve(i, 1, map[i][0])) result++; //�ε��� 1���ͽ���. ���̴� 0���ε���
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) 
			map[i][j] = map_cp[i][j]; //solve�Լ� �״�� ��������
	}

	for (int i = 0; i < N; i++) { //������ Ž��
		memset(visit, 0, sizeof(visit));
		if (solve(i, 1, map[i][0]))result++;		
	}
	cout << result;
}

