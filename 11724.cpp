#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//4963°ú ºñ½Á

int N, M;
vector<int> vec[1001];
int check[1001];

bool bfs(int start) {
	if (check[start]) return false;
	queue<int> q;
	q.push(start);
	check[start] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < vec[x].size(); i++){
			int y = vec[x][i];
			if (!check[y]) {
				check[y] = 1;
				q.push(y);
			}
		}
	}
	return true;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++){
		if(bfs(i)) cnt++;
	}
	cout << cnt << "\n";
}