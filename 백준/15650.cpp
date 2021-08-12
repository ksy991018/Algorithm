#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;

void solve(int cur) {
	if (v.size() == M) {
		for (int i = 0; i < M; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = cur; i <= N; i++) {
		v.push_back(i);
		solve(i + 1);
		v.pop_back();
	}

}

int main() {
	cin >> N >> M;
	solve(1);
}
