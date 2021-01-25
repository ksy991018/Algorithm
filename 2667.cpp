#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int map[26][26]; //지도
int N; //지도 크기
int c[26][26]; //다녀갔는지 확인 
int dx[4] = {1,-1,0,0 }; //상하좌우 
int dy[4] = {0,0,1,-1 };
int total=0; //단지수
int tmp[333] = { 0,}; //단지별 집의수

void dfs(int x, int y) {
	if (c[x][y] || !map[x][y]) return; //종료조건(이미 다녀갔거나, 집없는경우)

	c[x][y] = 1; //다녀간 표시
	tmp[total]++; //해당 단지의 집의수 추가

	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx <= 25 && cy <= 25 && cx>=1 && cy >=1) dfs(cx,cy);
	}
}

int main() {
	
	cin >> N;
	for (int i = 1; i <=N; i++){
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 1; i <=N; i++){
		for (int j = 1; j <= N; j++) {
			dfs(i, j);
			if (tmp[total] > 0) total++; //단지에 속하는 집이 있으면 다음 단지로
		}
	}

	cout << total << "\n";
	sort(tmp, tmp + total);
	for (int i = 0; i < total; i++){
		cout << tmp[i] << "\n";
	}
}