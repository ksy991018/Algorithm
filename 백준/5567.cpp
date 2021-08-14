#include <iostream>
#include <vector>
using namespace std;

int N, M;
int visit[501]; //초대여부
int cnt; //초대할 동기수
vector<int> v[501]; //친구 관계 그래프
vector<int> f; //상근이 친구

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) { 
			visit[b] = 1;
			f.push_back(b);
			cnt++;
		}
		else if (b == 1) {
			visit[a] = 1;
			f.push_back(a);
			cnt++;
		}
		else { //친구의 친구관계만 고려
			v[a].push_back(b);
			v[b].push_back(a);
		}
	}

	for (int i = 0; i < f.size(); i++) { //상근이 친구들의 관계만 탐색
		int cur = f[i];
		for (int j = 0; j < v[cur].size(); j++) {
			int next = v[cur][j];
			if (!visit[next]) {
				visit[next] = 1;
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}