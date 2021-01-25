#include <iostream>
using namespace std;

int N;
int garden[11][11];
int c[11][11];
int result = 1000000;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool check(int x, int y) {//���� üũ
	if (c[x - 1][y] || c[x + 1][y] || c[x][y + 1] || c[x][y - 1]) return false;
	return true;
}

void dfs(int start, int cnt) {
	if (cnt == 3) {//3���� �� ��� ���ϱ�
		int tmp = 0;
		for (int i = 1; i <=N; i++){
			for (int j = 1; j <= N; j++) {
				if (c[i][j]) tmp += garden[i][j];
			}
		}
		if (result > tmp) result = tmp; //�ּҺ��
		return;
	}

	for (int i = start; i < N; i++){
		for (int j = 2; j < N; j++) {
			if (check(i, j)) {
				c[i][j] = 1; //���� ��ġ üũ
				for (int k = 0; k < 4; k++){
					c[i + dx[k]][j + dy[k]] = 1;
				}
				dfs(i, cnt+1);
				//����Ʈ
				c[i][j] = 0;
				for (int k = 0; k < 4; k++) {
					c[i + dx[k]][j + dy[k]] = 0;
				}
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++) {
			int n;
			cin >> n;
			garden[i][j] = n;
		}
	}
	dfs(2,0);
	cout << result;
}

