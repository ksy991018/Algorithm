#include <iostream>
#include <vector>
using namespace std;

int N, S; //정수 개수 , 부분수열 합
int result; //부분수열 개수
int arr[20];

void solve(int cnt, int sum, int flag) { //flag: 그전 수열과 변화 유무
	if (cnt == N+1) return; 

	if (sum == S && flag) result++; //그전 수열과 똑같을때 중복 실행 방지 

	solve(cnt + 1, sum + arr[cnt],1);
	solve(cnt + 1, sum,0);
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}

	solve(0, 0, 0);
	cout << result;
}