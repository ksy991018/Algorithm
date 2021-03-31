#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, k;
int map[10000][10000];
int time;
int row = 3;
int col = 3;
int cnt[101]; //각 숫자가 몇번 나왔는지
bool flag = false;

void calcR() { //가로로 계산 
	int col_prev = col; //현재 열의 수 
	for (int i = 0; i < row; i++) {
		memset(cnt, 0, sizeof(cnt));
		vector<pair<int, int>> v;
		for (int j = 0; j < col; j++) {//등장횟수 체크
			cnt[map[i][j]]++;
		}
		for (int j = 1; j <= 100; j++) {
			if (cnt[j] > 0) v.push_back({ cnt[j],j }); //{몇번 등장,숫자}
		}
		for (int j = 0; j < col_prev; j++){ //현재 줄 0으로 초기화
			map[i][j] = 0;
		}
		sort(v.begin(), v.end()); //오름차순 정렬
		int size = v.size();
		for (int j = 0; j < size; j++) {
			if (j * 2 == 100) { //열의 크기 100넘어가면 뒤에다 버림 
				size = j;
				break;
			}
			map[i][j * 2] = v[j].second; //pair vector라서
			map[i][j * 2 + 1] = v[j].first;
		}
		col = max(col, 2 * size); //현재 열의수 초기화 
	}
}

void calcC() {
	int row_prev = row;
	for (int i = 0; i < col; i++) {
		memset(cnt, 0, sizeof(cnt));
		vector<pair<int, int>> v;
		for (int j = 0; j < row; j++) {
			cnt[map[j][i]]++;
		}
		for (int j = 1; j <= 100; j++) {
			if (cnt[j] > 0) v.push_back({ cnt[j],j });
		}
		for (int j = 0; j < row_prev; j++) {
			map[j][i] = 0;
		}
		sort(v.begin(), v.end());
		int size = v.size();
		for (int j = 0; j < size; j++) {
			if (j*2 == 100) {
				size = j;
				break;
			}
			map[j*2][i] = v[j].second;
			map[j*2+1][i] = v[j].first;
		}
		row = max(row, 2 * size);
	}
}

int main() {
	cin >> r >> c >> k;
	r--; c--; 
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}
	if (map[r][c] == k) flag = true;

	while (!flag &&time < 100) { //100초 전 & 값못찾음
		time++;
		if (row >= col) calcR();
		else calcC();
		if (map[r][c] == k) flag=true;
	}
	cout << (flag? time:-1);
}