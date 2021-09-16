#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
	dp[0][0] = triangle[0][0]; //�� �����
	int height = triangle.size() - 1;
	for (int i = 0; i < height; i++){ //�� �Ʒ������� ������
		for (int j = 0; j < triangle[i].size(); j++) { //�ش� ������ ���̸�ŭ
			for (int k = 0; k < 2; k++) { //����&������
				int next = triangle[i+1][j + k];
				dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + next); //������ ū�ɷ� ������Ʈ
			}
		}
	}
	for (int i = 0; i < triangle[height].size(); i++){//�� �Ʒ��� ���� ���� ū��
		answer = max(answer, dp[height][i]);
	}
    return answer;
}

int main() {
	cout << solution({ {7},{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5 } }) << endl;
}