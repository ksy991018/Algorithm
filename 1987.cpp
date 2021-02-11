#include <iostream>
#include <algorithm>
using namespace std;

int R, C;
char map[20][20];
int alpha[26]; //���ĺ� �湮ǥ��
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int result;//�ִ�ĭ ��

//����� Ư¡ -> DFS
void dfs(int x, int y,int cnt) {
	result = max(result, cnt);
	for (int i = 0; i < 4; i++){
		int cx = x + dx[i];
		int cy = y + dy[i];
		int pass = map[cx][cy] - 'A';
		if (cx >= 0 && cx < R && cy >= 0 && cy < C && !alpha[pass]) { //������ ���ĺ�X
			cnt++;
			alpha[pass] = 1; 
			dfs(cx, cy, cnt);
			cnt--;
			alpha[pass] = 0; //��Ʈ��ŷ
		}
	}	
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	int start = map[0][0] - 'A'; //char to int
	alpha[start] = 1;
	dfs(0, 0, 1); //������������ 1ĭ
	cout << result;
	
}