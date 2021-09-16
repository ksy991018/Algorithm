#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
	dp[0][0] = triangle[0][0]; //맨 꼭대기
	int height = triangle.size() - 1;
	for (int i = 0; i < height; i++){ //맨 아래높이의 위까지
		for (int j = 0; j < triangle[i].size(); j++) { //해당 높이의 길이만큼
			for (int k = 0; k < 2; k++) { //왼쪽&오른쪽
				int next = triangle[i+1][j + k];
				dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + next); //누적합 큰걸로 업데이트
			}
		}
	}
	for (int i = 0; i < triangle[height].size(); i++){//맨 아래의 값중 가장 큰거
		answer = max(answer, dp[height][i]);
	}
    return answer;
}

int main() {
	cout << solution({ {7},{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5 } }) << endl;
}