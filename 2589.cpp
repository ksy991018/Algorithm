#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
char map[50][50];
int visit[50][50];
vector<pair<int, int>> land;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int result;

void bfs(int x, int y) {
	queue<pair<pair<int, int>,int>> q; 
	q.push({{ x,y },0});
	visit[x][y] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second; //몇번째 접근
		result = max(result, cnt); //제일 멀리 나아간곳
		q.pop();
		for (int i = 0; i < 4; i++){
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (0 <= cx && cx < N && 0 <= cy && cy < M && map[cx][cy] == 'L') {
				if (!visit[cx][cy]) {
					visit[cx][cy] = 1;
					q.push({ {cx,cy},cnt + 1 });
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') land.push_back({ i,j });
		}
	}

	for (int i = 0; i < land.size(); i++){
		memset(visit, 0, sizeof(visit));
		bfs(land[i].first, land[i].second);
	}
	cout << result;
}