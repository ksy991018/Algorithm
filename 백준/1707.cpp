#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_SIZE 20001
#define RED 1
#define BLUE 2

using namespace std;

int T;
int V, E;
vector<int> graph[MAX_SIZE];
int visit[MAX_SIZE];

void bfs(int start) {
	queue<int> q;
	int color = RED;
	visit[start] = color;
	q.push(start);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		color = (visit[x] == RED)? BLUE : RED;
		
		for (int i = 0; i < graph[x].size(); i++){
			int y = graph[x][i];
			if (!visit[y]) {
				visit[y] = color;
				q.push(y);
			}
		}
	}
}

void dfs(int start) {
	if (!visit[start]) {
		visit[start] = RED;
	}
	for (int i = 0; i < graph[start].size(); i++){
		int y = graph[start][i];
		if (!visit[y]) {
			if (visit[start] == RED) visit[y] = BLUE;
			else visit[y] = RED;
			dfs(y);
		}
	}
}

bool check() {
	for (int i = 1; i <=V ; i++){
		int a = visit[i];
		for (int j = 0; j < graph[i].size(); j++){
			int b = visit[graph[i][j]];
			if (a == b) return false;
		}
	}
	return true;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> V >> E;
		for (int i = 0; i < E; i++){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for (int i = 1; i <=V ; i++){
			if(!visit[i]) dfs(i);
		}

		cout << (check() ? "YES" : "NO") << endl;
		
		for (int i = 1; i <=V ; i++){
			graph[i].clear();
		}

		memset(visit,  0,sizeof(visit));
	}
}