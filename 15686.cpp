#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//삼성 기출
//브루트포스 전체탐색
int N, M; //도시크기, 치킨집 최대수
int map[50][50];
int visit[13]; //치킨집 선택여부
vector<pair<int, int>> house; //집 좌표
vector<pair<int, int>> chicken; //치킨집 좌표
priority_queue<int,vector<int>,greater<int>> pq; //최솟값 출력

int distance(pair<int, int>a, pair<int, int>b) { //거리계산
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int cur, int cnt) { //cur : 현재 고려할 치킨집 인덱스 / cnt : 현재까지 선택한 치킨집 수
	if (cnt == M) { //치킨집 다골랐으면
		int result = 0;
		for (int i = 0; i < house.size(); i++) { //모든 집에 대해
			int tmp = 1000000;
			for (int j = 0; j < chicken.size(); j++) {//선정된 치킨집들과 거리중 최소거리 
				if (visit[j]) tmp = min(tmp,distance(chicken[j], house[i]));
			}
			result += tmp;
		}
		pq.push(result);
		return;
	}
	if (cur == chicken.size()) return; //치킨집 더이상 x
	visit[cur] = 1; //백트래킹
	dfs(cur + 1, cnt + 1);
	visit[cur] = 0;
	dfs(cur + 1, cnt);
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) house.push_back({ i,j });
			if (map[i][j] == 2) chicken.push_back({ i,j });
		}
	}
	dfs(0, 0);
	cout << pq.top(); //최솟값 출력
}