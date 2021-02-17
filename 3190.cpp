#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int N, K; //보드 크기, 사과개수
int D; //방향 변환수
int map[101][101];
int dx[4] = { 0,1,0,-1 }; //우,하,좌,상  D(오른쪽)는 +1 C(왼쪽)는 -1
int dy[4] = { 1,0,-1,0 };
int cnt; //현재 초
queue<pair<int, char>> change; //방향 변환
deque<pair<int, int>> snake; //뱀 (iterator 쓰려고 deque로)

bool check(int x, int y) {
	if (x <= 0 || x > N || y <= 0 || y > N) return false;
	for (auto i = snake.begin(); i < snake.end(); i++){ //자신이랑 부딪히는지 확인
		if (i->first == x && i->second == y) return false;
	}
	return true;
}

void solve(int dir,pair<int,int> cur) {

	if (!change.empty()) {//방향 전환 타임인지
		pair<int, char> tmp = change.front();
		if (tmp.first == cnt) { //방향 적용 & 제거
			change.pop(); 
			if (tmp.second == 'D') {
				if (dir + 1 == 4) dir = -1; //유의
				solve(dir + 1, cur);
				return;
			}
			if (tmp.second == 'L') {
				if (dir - 1 == -1) dir = 4; //유의
				solve(dir - 1, cur);
				return;
			}
		}
	}
	cnt++; //시간추가
	int x = cur.first + dx[dir]; //이동할 좌표
	int y = cur.second + dy[dir];

	if (!check(x, y)) return; //이동하고자 하는 좌표체크

	snake.push_back({ x,y });
	if (!map[x][y]) { //사과없다면
		snake.pop_front();//꼬리제거
		solve(dir, { x,y });
	}
	else {//사과있다면
		map[x][y] = 0; //사과지움
		solve(dir, { x,y });
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++){
		int a, b;
		cin >> a >> b;
		map[a][b] = 1; //사과표시
	}
	cin >> D;
	for (int i = 0; i <D ; i++){
		int c;
		char d;
		cin >> c >> d;
		change.push({ c,d }); //방향추가
	}

	snake.push_back({ 1,1 }); 
	solve(0,{ 1,1 }); //방향 & 출발위치
	cout << cnt;
}