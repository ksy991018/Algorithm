#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

char map[5][5];
int visit[5][5];
vector<pair<int, int>> person;
int dx[4] = { 0,0,1,-1};
int dy[4] = { 1,-1,0,0};
bool flag = true;

void dfs(int x, int y, int depth) {
	if (depth > 2) return;

	if (depth > 0 && map[x][y] == 'P') {
		flag = false;
		return;
	}
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++){
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx >= 0 && cx < 5 && cy >= 0 && cy < 5 && !visit[cx][cy] && map[cx][cy] != 'X') {
			dfs(cx, cy, depth + 1);
		}
	}
}

int solve() {
	flag = true;
	for (int i = 0; i < person.size(); i++){		
		dfs(person[i].first,person[i].second , 0);
		if (!flag) return 0;
	}
	return 1;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	for (int i = 0; i < places.size(); i++){
		person.clear();
		memset(visit, 0, sizeof(visit));
		for (int j = 0; j < 5; j++){
			for (int k = 0; k < 5; k++) {
				map[j][k]= places[i][j][k];
				if (map[j][k] == 'P') person.push_back({ j,k });
			}
		}
		int result = solve();
		answer.push_back(result);
	}

    return answer;
}

int main() {
	vector<int> v = solution({ {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
		{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
		{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
		{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
		{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP" } });

	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}