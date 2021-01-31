#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int w, h;
int map[50][50];
int check[50][50];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

bool bfs(int a, int b) {
	if (check[a][b]) return false; //방문한곳이면 즉시 종료
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (!check[x][y]) check[x][y] = 1;
		q.pop();
		for (int i = 0; i < 8; i++){
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx >= 0 && cx < h && cy >= 0 && cy < w) {
				if (map[cx][cy] && !check[cx][cy]) { 
					check[cx][cy] = 1;
					q.push(make_pair(cx, cy));
				}
			}
		}
	}
	return true; 
}

int main() {
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break; //종료조건
		memset(map, 0, sizeof(map));
		memset(check, 0, sizeof(check));
		vector<pair<int, int>> v; //섬의 위치
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++){
				cin >> map[i][j];
				if (map[i][j]) v.push_back(make_pair(i, j));
			}
		}
		int cnt = 0; // 섬의 개수
		for (int i = 0; i < v.size(); i++) {
			if (bfs(v[i].first, v[i].second)) cnt++;
		}
		cout << cnt << "\n";
	}
}