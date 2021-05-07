#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K; //맵크기, 상어 , 냄새 유지시간
int map[20][20];

int time; //출력
int live; //살아있는 상어
int dx[5] = {0, -1,1,0,0 };
int dy[5] = {0, 0,0,-1,1 };
vector<pair<int, pair<int, int>>> newLoc; //한 턴 끝나고 <몇번째상어,<이동할 위치>>

struct smell { //냄새
	int num; //어떤상어
	int remain; //남은 시간
};
smell s[20][20];

struct shark {
	int num;
	int x;
	int y;
	int dir; //1:위,2:아래,3:왼쪽,4:오른쪽
	int priority[4][4]; //위,아래,왼쪽,오른쪽
	bool safe = true;
};

shark fish[401];

void Decrease() { //냄새줄이기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (s[i][j].remain != 0) s[i][j].remain--;
			if (s[i][j].remain == 0) s[i][j].num = 0; //냄새 다없어지면 
		}
	}
}

bool check(int num, int move) { //빈공간 이동 가능여부
	int cx = fish[num].x + dx[move];
	int cy = fish[num].y + dy[move];
	if (cx >= 0 && cx < N && cy >= 0 && cy < N) {
		if (s[cx][cy].num == 0 && s[cx][cy].remain == 0) return true;
	}
	return false;
}


void solve() {
	while (live > 1 && time <=1000) {
		newLoc.clear();
		for (int i = M; i >= 1; i--){
			if (!fish[i].safe) continue;
			bool success = false;
			for (int j = 0; j< 4; j++){ //아무냄새 없는 칸 방향
				int want = fish[i].priority[fish[i].dir-1][j]; //현재 방향기준 우선 이동방향

				if (check(i, want)) {
					success = true; //칸이동 성공
					fish[i].x += dx[want];
					fish[i].y += dy[want];		
					fish[i].dir = want;
					newLoc.push_back({ i, {fish[i].x,fish[i].y} }); //이동할 위치 삽입
					break;
				}
			}
			if (!success) { //칸 이동성공 못했을때 자기냄새 방향으로 이동
				for (int j = 0; j < 4; j++) {
					int want = fish[i].priority[fish[i].dir-1][j]; //현재 방향기준 우선 이동방향
					int cx = fish[i].x + dx[want];
					int cy = fish[i].y + dy[want];
					if (cx >= 0 && cx < N && cy >= 0 && cy < N) {
						if (s[cx][cy].num == i) { //자기 냄새면
							fish[i].x =cx;
							fish[i].y = cy;
							fish[i].dir = want;
							newLoc.push_back({ i, {cx,cy} }); //이동할 위치 삽입
							break;
						}
					}
				}
			}
		}
		Decrease(); //냄새줄이기
		sort(newLoc.begin(), newLoc.end()); //상어번호 큰것부터 하려고
		for (int i = newLoc.size()-1; i >=0; i--) { //상어이동 
			auto tmp = newLoc[i];
			auto go =s[tmp.second.first][tmp.second.second];
			if (go.remain == K) { //번호 큰상어 방금이동했는데 더 작은 상어 이동할때 
				fish[go.num].safe = false; //잡아먹음
				live--;
			}
			s[tmp.second.first][tmp.second.second] = { tmp.first,K}; //위치지정
		}
		time++;
	}
}

int main() {
	cin >> N >> M >> K;
	live = M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;
			if (n!= 0) { //상어 위치,냄새 표시
				s[i][j] = { n,K };
				fish[n].x = i;
				fish[n].y = j;
			}
		}
	}

	for (int i = 1; i <= M; i++){ //상어 방향표시 
		fish[i].num = i;
		cin >> fish[i].dir;
	}

	for (int i = 1; i <= M; i++){ //상어 우선순위
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> fish[i].priority[j][k];
			}
		}
	}

	solve();
	cout << (time>1000? -1 : time);
}