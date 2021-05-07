#include <iostream>
#include <cstring>
using namespace std;

//dfs + dp 
//�ٽ� : Ž�������� ���̿��� �̹� Ž���ߴ� ���̸� �ش��������κ��� �����ִ� ����� ���� ������

int M, N;
int map[500][500];
int dp[500][500];   //����� ��
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int dfs(int x, int y) {
	if (x == M-1 && y == N-1) return 1; //�����ϸ� ����� �� �߰�
	
	if (dp[x][y] !=-1) return dp[x][y]; //�湮���� ������ �����س��� �ش��������� �����ִ� ��� �� ��ȯ

	dp[x][y] = 0; //�湮 ǥ�� 
	for (int i = 0; i < 4; i++){
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx >= 0 && cx < M && cy >= 0 && cy<N  && map[x][y]> map[cx][cy]) { //����o && �� ��������
			dp[x][y] += dfs(cx, cy); //����� �� �߰�
		}
	}
	return dp[x][y];
}


int main() {
	cin >> M >> N;
	memset(dp, -1, sizeof(dp)); //ó�� ���±����� �ƴ��� ���� ����. 
	//0���� �ʱ�ȭ�ϸ� �湮�߾ �����ϱ� ���̳� Ž�� �������̶� 0�ϼ� �����Ƿ� �湮���� ���� �Ұ�.

	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	cout << dfs(0,0);
	cout << dp[0][0];
}

//dfs�� �̿� -> �ð��ʰ�
//#include <iostream>
//using namespace std;
//
//int M, N;
//int map[500][500];
//int visit[500][500];
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int cnt;
//
//void dfs(int x, int y) {
//	if (x == M-1 && y == N-1) {
//		cnt++;
//		return;
//	}
//	visit[x][y] = 1;
//	cout << x << " " << y << endl;
//	int tmp = map[x][y];
//	for (int i = 0; i < 4; i++){
//		int cx = x + dx[i];
//		int cy = y + dy[i];
//		if (cx >= 0 && cx < M && cy >= 0 && cy<N && !visit[cx][cy] && tmp> map[cx][cy]) {
//			visit[cx][cy] = 1;
//			dfs(cx, cy);
//			visit[cx][cy] = 0;
//		}
//	}
//}
//
//
//
//int main() {
//	cin >> M >> N;
//	for (int i = 0; i < M; i++){
//		for (int j = 0; j < N; j++) {
//			cin >> map[i][j];
//		}
//	}
//	dfs(0,0);
//	cout << cnt;
//}