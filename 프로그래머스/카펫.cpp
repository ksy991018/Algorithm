#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
	int N,M; //���α���, ���α���
	for (int i = 1; i <= yellow; i++){ //�׵θ� ���� 
		if (yellow % i == 0) {//24��� 1X24, 2X12 , 3X8, 4X6 
			N = i;
			M = yellow / i;
		}
		int tmp = 2 * (N + M + 2); //���� ���¿��� �׵θ� ��
		if (tmp == brown) { //�־��� �׵θ����� ���ٸ� 
			answer.push_back(M + 2); answer.push_back(N + 2);
			break;
		}
	}
    return answer;
}

int main() {
	vector<int> v = solution(8, 1);
	cout << v[0] << " " << v[1] << endl;
}