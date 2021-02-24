#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N;
int map[21][21];
vector<pair<int,pair<int, int>>> fish; //물고기 <크기,<위치>>
int Ssize = 2; //아기상어 크기
int sharkX, sharkY; //출발위치
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int time; //시간 (출력값)
int eat; //몇마리 먹었는지 (사이즈 레벨업 위해서)
int visit[21][21];

int bfs(int x1, int y1,int x2,int y2) { //(x1,y1)에서 (x2,y2)까지 거리 계산
	memset(visit, 0, sizeof(visit));
	queue<pair<int,pair<int, int>>> q; //<시간,<좌표>>
	q.push({ 0,{ x1, y1 } });
	visit[x1][y1] = 1;
	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int tmpTime = q.front().first;
		q.pop();
		
		for (int i = 0; i < 4; i++){
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx > 0 && cx <= N && cy > 0 && cy <= N && map[cx][cy] <= Ssize && !visit[cx][cy]) { 
				if (cx == x2 && cy == y2) return time+1;
				q.push({tmpTime + 1,{cx, cy}});
				visit[cx][cy] = 1;
			}
		}
	}
	return 0;
}

void solve() {	
	while (true) {
		int result = 1000000;
		int targetFish = -1;
		//내가 잡을 물고기 1마리 선택
		for (int i = 0; i < fish.size(); i++) { 
			if (fish[i].first < Ssize) { //먹을수 있는 물고기중 (나보다 작은 물고기 중)
				int tmp = bfs(sharkX, sharkY, fish[i].second.first, fish[i].second.second); //거리계산
				if (tmp>0 && result > tmp) { //제일 가까운 물고기. 거리 같은 경우도 먼저 계산된게 우선순위.
					targetFish = i;
					result = tmp;
				}
			}
		}
		if (targetFish == -1 || fish.size()==0) break; //먹을수 있는 물고기 없으면 
		eat++; //물고기 먹음
		if (eat == Ssize) { //사이즈만큼 먹으면 레벨업
			Ssize++;
			eat = 0;
		}
			
		time += result; //거리와 시간 동일하므로 
		
		sharkX = fish[targetFish].second.first; //방금 잡아먹은 물고기의 위치로 상어 이동
		sharkY = fish[targetFish].second.second;
		fish.erase(fish.begin() + targetFish); //먹은 물고기 비우기
		map[sharkX][sharkY] = 0; //먹은 물고기 흔적도 지우기 
	}	
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] <= 6) {
				fish.push_back({ map[i][j],{i,j} }); 
				//맨위 맨왼쪽부터 물고기 넣기때문에, 추후 거리 동일한 물고기들의 우선순위 따로 정의할 필요없음. 앞에 인덱스부터 고려하면 됨.

			}
			if (map[i][j] == 9) {
				sharkX = i;
				sharkY = j;
				map[i][j] = 0; //상어 위치 표기한후 0으로
			}
		}
	}
	solve();
	cout << time; //종료시점 시간
}