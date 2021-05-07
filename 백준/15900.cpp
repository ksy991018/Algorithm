#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v[500001];
int visit[500001];
int cnt; //간선수

void dfs(int start, int depth) {
	if (v[start].size()==1 && start!=1) { //리프노드일때
		cnt+=depth;
		return;
	}
	for (int i = 0; i < v[start].size(); i++){
		if (!visit[start]) { //백트래킹
			visit[start] = 1;
			dfs(v[start][i], depth + 1);
			visit[start] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N-1; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1,0);
	cout << (cnt%2!=0 ?"Yes":"No");  //간선 홀수면 승리 
}