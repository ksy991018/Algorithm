#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int map[500][500];
int visit[500][500];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int result; //��Ʈ�ι̳� �� �ִ�

void dfs(int x, int y,int sum,int cnt) {
	if (cnt == 4) {
		result = max(result, sum);
		return;
	}
	for (int i = 0; i < 4; i++){
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (0 <= cx && cx < N && 0 <= cy && cy < M && !visit[cx][cy]) {
			visit[cx][cy]=1;
			dfs(cx, cy, sum+map[cx][cy],cnt+1);
			visit[cx][cy] = 0; //��Ʈ��ŷ
		}
	}
}

void special(int x, int y) { //Ư���� ��� �ϵ��ڵ�. ȸ���ؼ� �Ǹ���϶� �ǿ��� �ε��� ����
	int tmp=0;
	//"��"
	if (x -1 >=0 && y + 2 < M) {
		tmp = map[x][y] + map[x - 1][y + 1] + map[x][y + 1] + map[x][y + 2];
		result = max(tmp, result);
	}
	//"��"
	if (x - 2 >= 0 && y - 1 >= 0) {
		tmp = map[x][y] + map[x - 2][y] + map[x - 1][y] + map[x - 1][y - 1];
		result = max(tmp, result);
	}
	//"��"
	if (x + 2 < N && y + 1 < M) {
		tmp = map[x][y] + map[x + 1][y] + map[x + 1][y + 1] + map[x + 2][y];
		result = max(tmp, result);
	}
	//"��"
	if (x + 1 < N && y - 2 >= 0) {
		tmp = map[x][y] + map[x][y - 1] + map[x][y - 2] + map[x + 1][y - 1];
		result = max(tmp, result);
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 1;
			dfs(i, j, map[i][j], 1); //���� ��ǥ ����
			visit[i][j] = 0; //��Ʈ��ŷ
			special(i, j); 
		}
	}
	cout << result;
}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//int N, M;
//int map[500][500];
//int visit[500][500];
//int dx[4] = { 0,0,1,-1 };
//int dy[4] = { 1,-1,0,0 };
//int result;
//
//bool check(int cx, int cy) {
//	if (0 <= cx && cx < N && 0 <= cy && cy < M) return true;
//	return false;
//}
//
//void dfs(int x, int y,int sum,int cnt) {
//	if (cnt == 4) {
//		result = max(result, sum);
//		return;
//	}
//
//	for (int i = 0; i < 4; i++){
//		int cx = x + dx[i];
//		int cy = y + dy[i];
//		if (check(cx,cy)) {
//			if (visit[cx][cy]==0) {
//				visit[cx][cy]=1;
//				dfs(cx, cy, sum+map[cx][cy],cnt+1);
//				visit[cx][cy] = 0;
//			}
//			else if(visit[cx][cy]==1) {
//				visit[cx][cy]++;
//				dfs(cx, cy, sum,cnt);
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> N >> M;
//	for (int i = 0; i < N; i++){
//		for (int j = 0; j < M; j++) {
//			cin >> map[i][j];
//		}
//	}
//	int tx[2] = { 0,1 };
//	int ty[2] = { 1,0 };
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			memset(visit, 0, sizeof(visit));
//			visit[i][j] = 1;
//			for (int k = 0; k < 2; k++){
//				int x = i + tx[k];
//				int y = j + ty[k];
//				if (check(x, y)) {	
//					visit[x][y] = 1;
//					dfs(x, y, map[i][j]+map[x][y],2);
//					visit[x][y] = 0;		
//				}
//			}
//
//		}
//	}
//	cout << result;
//}