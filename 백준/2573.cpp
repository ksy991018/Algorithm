#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[300][300];
int map_cp[300][300];
int visit[300][300];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int turn;
queue<pair<int, int>> q;

void copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = map_cp[i][j];
		}
	}
}

bool check() {
	memset(visit, 0, sizeof(visit));
	int a = q.front().first;
	int b = q.front().second;
	int size = q.size();
	int cnt = 0;
	
	queue<pair<int, int>> tmp;
	tmp.push({ a,b });
	visit[a][b] = 1;
	while (!tmp.empty()) {
		int x = tmp.front().first;
		int y = tmp.front().second;
		cnt++;	
		tmp.pop();
		for (int i = 0; i < 4; i++) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			
			if (cx >= 0 && cx < N && cy >= 0 && cy < M) {
				if (!visit[cx][cy] && map[cx][cy] != 0) {
					visit[cx][cy] = 1;
					tmp.push({ cx,cy });
				}
				
			}
		}
	}
	if (cnt == size) return true;
	else return false;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				q.push({ i,j });
			}
		}
	}

	while (true) {
		memset(map_cp, 0, sizeof(map_cp));
		int size = q.size();
		if (!check() || size==0) break;

		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			int cnt = 0;
			for (int j = 0; j < 4; j++) {
				int cx = x + dx[j];
				int cy = y + dy[j];
				if (cx >= 0 && cx < N && cy >= 0 && cy < M && map[cx][cy] == 0) {
					cnt++;
				}
			}
			int newValue = map[x][y] - cnt;
			if (newValue > 0) {
				map_cp[x][y] = newValue;
				q.push({ x,y });
			}
		}
		copy();
		turn++;
	}
	if (q.size() == 0) turn = 0;
	cout << turn << endl;
}