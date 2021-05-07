#include<iostream>
#include <queue>
#include<cstring>
#include <vector>
using namespace std;

//아이디어 : 비의 양이 주어졌을때, 비의 양보다 큰 높이 가진 곳들을 no_sink로 표시해주고 
//no_sink들 중에 인접해있는 것들을 1개로 봄. 인접된거 없이 자기혼자라면 그자체로 1개.

int N;
int map[100][100];
int no_sink[100][100]; //비의 양이 주어졌을때 안잠기는곳은 1로 표시
int visit[100][100]; //방문했는지
int max_depth; //최대 비의양 설정하기 위해 가장 큰 높이 저장
int protect[101]; //인덱스:비의 양 & 값 : 안전영역
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int result; //출력 : protect값중 제일 큰값

bool is_inside(int x, int y) {
	if (0 <= x && x < N && 0 <= y && y < N) return true;
	return false;
}

bool bfs(int x,int y) { //방문표시가 핵심
	if (visit[x][y]) return false;
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (is_inside(cx, cy)&& !visit[cx][cy] && no_sink[cx][cy]) { //범위 && 방문x && 안잠김 만족
				visit[cx][cy] = 1;
				q.push({ cx,cy });
			}
		}
	}
	return true;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (max_depth < map[i][j]) max_depth = map[i][j]; //가장 큰높이 저장
		}
	}

	for (int i = 0; i <= max_depth; i++){//현재 비의 양
		memset(no_sink, 0, sizeof(no_sink)); //비의 양에 따른 모든케이스 계산하기 위해
		memset(visit, 0, sizeof(visit));
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (map[j][k] > i) no_sink[j][k] = 1; //비의 양보다 높이높으면 안잠김 표시
				
			}
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (no_sink[j][k]) { //안잠기는 경우만 탐색
					if (bfs(j, k)) protect[i]++; //bfs가 참이면 안전영역 증가
				}
			}
		}
		if (result < protect[i]) result = protect[i]; //protect중 가장 큰값 출력위해
	}
	cout << result;
}