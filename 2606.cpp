#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> v[101];
int c[101];
int N, M;

int bfs(int start) {
	queue<int> q;
	q.push(start);
	c[start] = true;
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < v[x].size(); i++){
			int y = v[x][i];
			if (!c[y]) {
				c[y] = true;
				q.push(y);
			}
		}
	}
	return cnt;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	cout << bfs(1)-1;
}