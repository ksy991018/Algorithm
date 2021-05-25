#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
int map[1001][1001];
int result;
int dp[1001][1001];//좌표를 정사각형의 맨오른쪽아래 꼭짓점으로 생각했을때 만들수있는 최대 정사각형의 크기

int main() {
	cin >> N >>  M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j]) dp[i][j] = 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) { 
			if (map[i][j]== 1 && dp[i - 1][j] != 0 && dp[i - 1][j - 1] != 0 && dp[i][j - 1] != 0) {
				int size = min({ dp[i][j - 1],dp[i - 1][j],dp[i - 1][j - 1] });
				int tmp = sqrt(size)+1; //기존 정사각형 한변의 길이 +1
				dp[i][j] = tmp * tmp;
				result = max(result, dp[i][j]);
			}
		}
	}
	if (result == 0) result = dp[1][1]; //1x1인경우 예외처리
	cout << result;
}
