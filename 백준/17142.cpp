#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int map[50][50]; //0:빈칸, 1:벽, 2: 바이러스
int visit[50][50];
int minTime = 987654321;//바이러스 모두 퍼지는 최소시간
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<pair<int,int>> v; //바이러스 위치
vector<pair<int, int>> tmp; //활성화 바이러스 위치
int tmpvisit[10]; //백트래킹
int blank; //빈칸 수 <- 시간초과때문에 사용


void SpreadVirus() { //활성화 바이러스 퍼뜨리기
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> q;
	for (int i = 0; i < tmp.size(); i++){ //활성화 바이러스
		q.push(tmp[i]);
		visit[tmp[i].first][tmp[i].second] = 1;
	}
	int cnt = 0; //현재 시간
	int blankcnt = 0; //바이러스가 퍼진 빈칸의 수 <- 시간초과 방지

	while (!q.empty() && blankcnt<blank) { //bfs
		int size = q.size();
		cnt++; 
		while(size--){		
			int x = q.front().first;
			int y = q.front().second;
			q.pop(); 		
			for (int i = 0; i < 4; i++){
				int cx = x + dx[i];
				int cy = y + dy[i];
				if (cx >= 0 && cx < N && cy >= 0 && cy < N && !visit[cx][cy] && map[cx][cy] != 1) {//범위o,방문x,벽x
					if(map[cx][cy]==0) blankcnt++; //빈칸인데 바이러스 퍼진경우 <- 비활성화 바이러스 칸이랑 차별위해
					visit[cx][cy] = 1;
					q.push({ cx,cy });
				}
			}
		}
	}
	if (blankcnt == blank) minTime = min(minTime, cnt);
}

void Activate(int cur) { //활성화 바이러스 M개 선택 : 백트래킹
	if (tmp.size() == M) {
		SpreadVirus();
		return;
	}
	if (cur >= v.size()) return;
	for (int i = cur; i < v.size(); i++){
		if (!tmpvisit[i]) {
			tmpvisit[i] = 1;
			tmp.push_back(v[i]);
			Activate(i + 1);
			tmp.pop_back();
			tmpvisit[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	bool noVirus = true; //바이러스 유무
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) v.push_back({ i,j }); //바이러스
			if (map[i][j] == 0) { //빈칸
				blank++;
				noVirus = false;
			}
		}
	}
	if (!noVirus) Activate(0); //바이러스 있으면
	else minTime = 0; //바이러스 없으면
	cout << (minTime==987654321? -1 : minTime) << endl;
}