#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int A[10][10];
vector<int> map[10][10]; //나무들 나이 
int value[10][10]; //양분
int result; //남은 나무수
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

void SpringSummer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j].size() > 0) {
				sort(map[i][j].begin(), map[i][j].end()); //어린나무부터

				int nutrient = 0;
				vector<int> temp; //다음턴의 나무 나이
				for (int k = 0; k < map[i][j].size(); k++) {
					int age = map[i][j][k];
					if (value[i][j] >= age) {
						value[i][j] -= age; //양분 섭취
						temp.push_back(age + 1); //나이 한살 증가
					}
					else { //나무 죽는경우
						nutrient += (age / 2); //남기고간 양분			
					}	
				}
				map[i][j].clear();
				for (int k = 0; k < temp.size(); k++) {
					map[i][j].push_back(temp[k]);
				}
				value[i][j] += nutrient;
			}
		}
	}
}

void FallWinter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < map[i][j].size(); k++) {
				if (map[i][j][k] % 5 == 0) {
					for (int t = 0; t < 8; t++) {
						int cx = i + dx[t];
						int cy = j + dy[t];
						if (cx >= 0 && cx < N && cy >= 0 && cy < N) {
							map[cx][cy].push_back(1);
						}
					}
				}
			}
			value[i][j] += A[i][j]; 
		}
	}
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			value[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		map[x-1][y-1].push_back(age); //인덱스 0부터
	}

	while (K--) {
		SpringSummer();
		FallWinter();
	}

	//남은 나무
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) {
			result += map[i][j].size();
		}
	}
	cout << result << endl;
}


