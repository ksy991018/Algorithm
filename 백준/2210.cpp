#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int map[5][5];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
set<int> s;

void dfs(int x, int y, int cnt, int sum) {
	if (cnt == 6) {
		s.insert(sum);
		return;
	}

	for (int i = 0; i < 4; i++){
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx >= 0 && cx < 5 && cy >= 0 && cy < 5) {
			dfs(cx, cy, cnt + 1, sum + pow(10,cnt) * map[cx][cy]);
		}
	}
}

int main() {
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, 0, 0);
		}
	}
	cout << s.size();
}