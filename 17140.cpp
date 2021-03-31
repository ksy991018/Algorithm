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
int cnt[101]; //�� ���ڰ� ��� ���Դ���
bool flag = false;

void calcR() { //���η� ��� 
	int col_prev = col; //���� ���� �� 
	for (int i = 0; i < row; i++) {
		memset(cnt, 0, sizeof(cnt));
		vector<pair<int, int>> v;
		for (int j = 0; j < col; j++) {//����Ƚ�� üũ
			cnt[map[i][j]]++;
		}
		for (int j = 1; j <= 100; j++) {
			if (cnt[j] > 0) v.push_back({ cnt[j],j }); //{��� ����,����}
		}
		for (int j = 0; j < col_prev; j++){ //���� �� 0���� �ʱ�ȭ
			map[i][j] = 0;
		}
		sort(v.begin(), v.end()); //�������� ����
		int size = v.size();
		for (int j = 0; j < size; j++) {
			if (j * 2 == 100) { //���� ũ�� 100�Ѿ�� �ڿ��� ���� 
				size = j;
				break;
			}
			map[i][j * 2] = v[j].second; //pair vector��
			map[i][j * 2 + 1] = v[j].first;
		}
		col = max(col, 2 * size); //���� ���Ǽ� �ʱ�ȭ 
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

	while (!flag &&time < 100) { //100�� �� & ����ã��
		time++;
		if (row >= col) calcR();
		else calcC();
		if (map[r][c] == k) flag=true;
	}
	cout << (flag? time:-1);
}