#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N;
int cntR, cntG, cntB, cntRG; //구역개수
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char map[100][100];
int check[100][100];
//구역
vector<pair<int, int>> r;
vector<pair<int, int>> g;
vector<pair<int, int>> b;
vector<pair<int, int>> rg;

bool bfs(char c,int a,int b) {
	if (check[a][b]) return false;
	queue<pair<int,int>> q;
	q.push(make_pair(a, b));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx >= 0 && cx < N && cy >= 0 && cy < N && !check[cx][cy]) {
				if (c == 'A') { //적록색약
					if (map[cx][cy] !='B') { //R,G면 OK
						check[cx][cy] = 1;
						q.push(make_pair(cx, cy));
					}
				}else {
					if (map[cx][cy] == c) {
						check[cx][cy] = 1;
						q.push(make_pair(cx, cy));
					}
				}
			}
		}
	}
	return true;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				r.push_back(make_pair(i, j));
				rg.push_back(make_pair(i, j));
			}
			if (map[i][j] == 'G') {
				g.push_back(make_pair(i, j));
				rg.push_back(make_pair(i, j));
			}
			if (map[i][j] == 'B') b.push_back(make_pair(i, j));
		}
	}
	//적록색약 x
	for (int i = 0; i < r.size();i++){
		if(bfs('R',r[i].first,r[i].second)) cntR++;
	}
	for (int i = 0; i < g.size(); i++) {
		if (bfs('G', g[i].first, g[i].second)) cntG++;
	}
	for (int i = 0; i < b.size(); i++) {
		if (bfs('B', b[i].first, b[i].second)) cntB++;
	}

	//적록색약 o 
	memset(check, 0, sizeof(check)); //재탕
	for (int i = 0; i < rg.size(); i++) {
		if (bfs('A', rg[i].first, rg[i].second)) cntRG++; //차별성
	}
	cout << cntR + cntG + cntB << " " << cntRG + cntB;
}