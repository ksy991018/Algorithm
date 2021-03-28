#include <iostream>
#include <algorithm>
#define INF 10000000
using namespace std;

int N, M, H; //세로선,가로선,가로선위치수
int visit[31][11]; //[a][b] --->  b & b+1세로선 사이를 a번 가로선이 연결
int result=INF;

bool check() { //I번 세로선 결과가 I번인지 테스트 
	for (int i = 1; i <= N; i++) {
		int curr = i; //현재 세로선 
		for (int j = 1; j <= H; j++) {
			if (visit[j][curr]) curr++; //앞
			else if(visit[j][curr-1]) curr--; //뒤
		}
		if (curr != i) return false; 
	}
	return true;
}

void solve(int idx, int cnt) { //idx : 가로선
	if (cnt > 3) return;

	if (check()) {
		result = min(result, cnt);
		return;
	}
	for (int i = idx; i <= H; i++) {
		for (int j =1; j <= N; j++) {
			if (!visit[i][j + 1] && !visit[i][j - 1] && !visit[i][j]) { //가로선 연속 x
				visit[i][j] = 1;
				solve(i, cnt + 1);
				visit[i][j] = 0;
			}
			
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> H;
	for (int i = 0; i < M; i++){ //미리 가로선연결
		int a, b;
		cin >> a >> b;
		visit[a][b] = 1;
	}
	solve(1, 0);
	cout << (result == INF ? -1 : result);
}