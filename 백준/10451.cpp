#include <iostream>
#include <cstring>
using namespace std;

int T,N;
int n[1001];
int visit[1001];
int cnt;

void solve(int i) {
	if (visit[i]) return;
	visit[i] = 1;
	solve(n[i]);
}

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		memset(visit, 0, sizeof(visit));
		cnt = 0;
		for (int i = 1; i <= N; i++){
			cin >> n[i];
		}
		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {
				cnt++;
				solve(i);
			}
		}
		cout << cnt << endl;
	}
}