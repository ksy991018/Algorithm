#include <iostream>
#include <queue>
using namespace std;

int N, M; //전체 사람수, 부모자식 관계수
int from,to; //촌수 계산 대상
int visit[101]; 
int relation[101][101]; //그래프
int depth[101]; //from대상으로 촌수 계산

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = 1;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int i = 1; i <= N; i++){
			if (relation[tmp][i] && !visit[i]) {
				visit[i] = 1;
				depth[i] = depth[tmp] + 1; //포인트
				q.push(i);
			}
		}
	}
}

int main() {
	cin >> N;
	cin >> from >> to;
	cin >> M;
	for (int i = 0; i < M; i++){
		int parent, child;
		cin >> parent >> child;
		relation[parent][child] = 1;
		relation[child][parent] = 1;
	}
	bfs(from);

	cout << (depth[to] != 0 ? depth[to] : -1);
}