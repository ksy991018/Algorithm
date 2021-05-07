#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N; //편의점 개수
int startX, startY;
int endX, endY;
vector<pair<int, int>> v; //편의점 위치& 도착위치(고정된 좌표)
int visit[101];//편의점 방문여부

//한번에 1000m까지 이동 가능

int distance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

string bfs() {
	queue<pair<int, int>> q;
	q.push({ startX,startY });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		if (x == endX && y == endY) return "happy";

		for (int i = 0; i < v.size(); i++){
			int cx = v[i].first;
			int cy = v[i].second;
			if (distance(x, y, cx, cy) <= 1000 && !visit[i]) {
				visit[i] = 1;
				q.push({ cx,cy });
			}
		}
	}
	return "sad";
}

int main() {
	cin >> T;
	while (T--) {
		v.clear();
		memset(visit, 0, sizeof(visit));
		cin >> N;
		cin >> startX >> startY;
		for (int i = 0; i < N; i++){
			int x, y;
			cin >> x >> y;
			v.push_back({ x,y });
		}
		cin >> endX >> endY;
		v.push_back({ endX,endY });
		cout << bfs() << "\n";
	}
}
