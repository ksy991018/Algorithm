#include <iostream>
using namespace std;

int T, N, M;
int result[30][30];

int calc(int n, int c) { //파스칼 삼각형
	if (n == c || c == 0) return 1;
	if (c == 1) return n;

	if (result[n][c] == 0) result[n][c] = calc(n - 1, c - 1) + calc(n - 1, c); //계산한적있으면 그대로 사용. 이거안쓰면 시간초과
	return result[n][c];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		cout << calc(M, N) << "\n";
	}
}