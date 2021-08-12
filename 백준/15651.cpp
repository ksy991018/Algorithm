#include <iostream>
#include <vector>
using namespace std;

int M, N;
int arr[8];

void solve(int cur) {
	if (cur==M+1) {
		for (int i = 1; i <= M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\N";
		return;
	}
	for (int i = 1; i <= N; i++) { //중복 허용
		arr[cur] = i;
		solve(cur+1);
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	solve(1);
}