#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int map[1001][1001];
int visit[1001][1001][2]; //마지막 인덱스 : 벽 부실수있는 횟수, visit:몇번째 이동인지
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

//핵심 : 벽 부시고 가는 경우, 아닌 경우 둘다 고려
//visit 2차원배열 -> 벽부시고 간 경로와 안부시고 간 경로가 같은 노드에서 만나면 문제생김
//visit 3차원 배열 -> 위 두가지 경우 따로 방문 체크해줌

bool is_inside(int x, int y) {
	if (x >= 1 && x <= N && y >= 1 && y <= M) return true;
	return false;
}

int bfs() {
	queue<pair<pair<int, int>,int>> q; 
	q.push({ { 1,1 },1 }); //벽 부실기회 : 1
	visit[1][1][1] = 1; //이동 1에서 시작
	visit[1][1][0] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int block = q.front().second;
		q.pop();

		int tmp = visit[x][y][block]; //현재 누적이동
		if (x == N && y == M) return tmp;
		for (int i = 0; i < 4; i++) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (is_inside(cx,cy)) {
				if (block && map[cx][cy]) { //벽이고 부실기회 있을때 
					visit[cx][cy][block - 1] = tmp + 1; //부시고 기회 -1, 이동+1
					q.push({ {cx,cy},block - 1 });
				}
				if (!map[cx][cy] && !visit[cx][cy][block]) { //벽아니고 방문한적 없을때 
					visit[cx][cy][block] = tmp + 1; //기회 유지, 이동+1
					q.push({ {cx,cy},block });
				}
			}
		}
	}
	return 0; //못 빠져나왔을때
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	int result = bfs();
	cout << (result!= 0 ? result : -1);
}

