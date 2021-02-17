#include <iostream>
#include <vector>
#define INF 100000000
using namespace std;

int N; //수의 개수
int arr[12];
int oper[4];  //사용 가능 연산자 개수 { '+','-','*','/' } 
vector<int> v; //(연산자 -> 숫자로 바꿔서 넣음)
int visit[4]; //사용한 연산자 개수
int maxR = -INF;
int minR=INF;

void solve(int cnt) {//cnt:연산자 개수
	if (cnt == N - 1) { //종료조건 : 연산자개수 = 수의개수-1
		int result = arr[0];
		for (int i = 0; i < v.size(); i++){
			if (v[i] == 0) {
				result += arr[i + 1];
			}
			else if (v[i] == 1) {
				result -= arr[i + 1];
			}
			else if (v[i] == 2) {
				result *= arr[i + 1];
			}
			else if (v[i] == 3) {
				result /= arr[i + 1];
			}
		}
		if (result > maxR) maxR = result;
		if (result < minR) minR = result;
		return;
	}

	for (int i = 0; i < 4; i++){ //백트래킹
		if (visit[i] < oper[i]) { //연산자 개수
			visit[i]++;
			v.push_back(i); //연산자를 나타내는 숫자를 넣음
			solve(cnt + 1);
			v.pop_back();
			visit[i]--;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){//숫자
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++){//연산자개수
		cin >> oper[i];
	}

	solve(0);
	cout << maxR << "\n" << minR;
}