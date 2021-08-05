#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M,a,b;
vector<int> map[10001];
bool visit[10001];
int best; //현재까지 해킹가능한 최댓값
int tmp;

//인접행렬로 풀면 시간초과. 

void dfs(int cur) {
	visit[cur] = 1;
	for (int i = 0; i < map[cur].size(); i++) {
		int next = map[cur][i];
		if (!visit[next]) {
			tmp++;
			dfs(next);
		}
	}
	//시작노드 기준으로 여러 경우가 나와도 각 경우에 대해 일일히 카운트해서 최댓값이랑 비교할 필요없음.
	//매개변수를(int cur, int cnt)로하고  tmp=max(tmp,cnt) 로 하면 시간초과. 
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[b].push_back(a); //단방향 그래프
	}

	vector<int> result;
	for (int i = 1; i <= N; i++) {
		tmp = 0; //현재 컴퓨터에서 해킹할수있는 최대수
		memset(visit, 0, sizeof(visit));
		dfs(i);
		if (best <= tmp) {
			if (best < tmp) {
				result.clear();
				best = tmp;
			}
			result.push_back(i);
		}
	}
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;

	return 0;
}