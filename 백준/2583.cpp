#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int M, N, K; //가로,세로,직사각형 수
int map[100][100]; //직사각형 내부는 1
int visit[100][100];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<int> result; //영역개수

void bfs(int a, int b) {
	if (visit[a][b]) return;

	int size = 0;
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		size++;
		for (int i = 0; i < 4; i++) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx >= 0 && cx < M && cy >= 0 && cy < N && !visit[cx][cy] && !map[cx][cy]) {
				visit[cx][cy] = 1;
				q.push({ cx,cy });
			}
		}
	}
	result.push_back(size);
}

int main() {
	cin >> M >> N >> K;

	while (K--) { //직사각형 칠하기
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++){
			for (int j = x1; j < x2; j++) {
				map[i][j] = 1;
			}
		}
	}

	for (int i = 0; i <M ; i++){
		for (int j = 0; j < N; j++) {
			if (!map[i][j]) { //직사각형 외부
				bfs(i,j);
			}
		}
	}

	sort(result.begin(),result.end());
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}