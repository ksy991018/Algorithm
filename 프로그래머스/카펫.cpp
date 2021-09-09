#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
	int N,M; //세로길이, 가로길이
	for (int i = 1; i <= yellow; i++){ //테두리 제외 
		if (yellow % i == 0) {//24라면 1X24, 2X12 , 3X8, 4X6 
			N = i;
			M = yellow / i;
		}
		int tmp = 2 * (N + M + 2); //현재 상태에서 테두리 수
		if (tmp == brown) { //주어진 테두리수와 같다면 
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