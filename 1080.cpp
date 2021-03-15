#include <iostream>
#include <algorithm>
using namespace std;


int N, M;
int T = 2;
int map[50][50];
int cnt; //연산횟수
bool flag = true;

void flip(int x, int y) {
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++) {
			map[x + i][y + j] = !map[x + i][y + j];
		}
	}
	cnt++;
}

int main() {
	cin >> N >> M;

	while (T--) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if(T==1) scanf("%1d", &map[i][j]); 
				else { //1 : 다름, 0 : 같음 -> 1일경우만 flip
					int tmp;
					scanf("%1d", &tmp);
					map[i][j] = (tmp == map[i][j] ? 0 : 1);
				}
				
			}
		}
	}

	for (int i = 0; i < N-2; i++) {
		for (int j = 0; j < M-2; j++) {
			if (map[i][j]) flip(i, j);	//3X3 행렬의 맨왼쪽 맨위를 기준. (0,0)~(N-3,M-3)	
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) flag = false;  
		}
	}

	cout << (flag ? cnt : -1);
}