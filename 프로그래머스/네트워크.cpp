#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;



int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	vector<int> v[201];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			if (computers[i][j] == 1 && i != j) {
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}
	int visit[201] = { 0, };
	for (int i = 0; i < n; i++){
		if (!visit[i]) {
			queue<int> q;
			q.push(i);
			visit[i] = 1;
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				for (int j = 0; j < v[cur].size(); j++){
					int next = v[cur][j];
					if (!visit[next]) {
						q.push(next);
						visit[next] = 1;
					}
				}
			}
			answer++;
		}
	}

	return answer;
}

int main() {
	cout << solution(3, { {1, 1, 0},{1, 1, 0},{0, 0, 1} });
}