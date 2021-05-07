#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int map[26][26]; //����
int N; //���� ũ��
int c[26][26]; //�ٳబ���� Ȯ�� 
int dx[4] = {1,-1,0,0 }; //�����¿� 
int dy[4] = {0,0,1,-1 };
int total=0; //������
int tmp[333] = { 0,}; //������ ���Ǽ�

void dfs(int x, int y) {
	if (c[x][y] || !map[x][y]) return; //��������(�̹� �ٳబ�ų�, �����°��)

	c[x][y] = 1; //�ٳణ ǥ��
	tmp[total]++; //�ش� ������ ���Ǽ� �߰�

	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx <= 25 && cy <= 25 && cx>=1 && cy >=1) dfs(cx,cy);
	}
}

int main() {
	
	cin >> N;
	for (int i = 1; i <=N; i++){
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 1; i <=N; i++){
		for (int j = 1; j <= N; j++) {
			dfs(i, j);
			if (tmp[total] > 0) total++; //������ ���ϴ� ���� ������ ���� ������
		}
	}

	cout << total << "\n";
	sort(tmp, tmp + total);
	for (int i = 0; i < total; i++){
		cout << tmp[i] << "\n";
	}
}