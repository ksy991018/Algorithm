#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int c[1001];
int d[1001];
vector<int> v[1001];
int N, M,start;

void bfs(int start) {
	queue<int> q;
	q.push(start);
	d[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (int i = 0; i < v[x].size(); i++){
			int y = v[x][i];
			if (!d[y]) {
				q.push(y);
				d[y] = true;
			}
			
		}
	}
}

void dfs(int start) {
	if (c[start]) return;
	c[start] = true;
	cout << start << " ";
	for (int i = 0; i < v[start].size(); i++){
		int y = v[start][i];
		dfs(y);
	}
}

int main() {
	cin >> N >> M >> start;

	for (int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for (int i = 1; i <= N; i++){
		sort(v[i].begin(), v[i].end());
	}

	dfs(start);
	cout << endl;
	bfs(start);
}