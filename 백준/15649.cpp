#include <iostream>
#include <vector>
using namespace std;

int N, M;
int visit[9];
int arr[9];
vector<int> v;

void dfs(int cnt) {
	if (cnt == M+1) {
		for (int i = 0; i < v.size(); i++){
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++){
		if (!visit[i]) {
			visit[i] = 1;
			v.push_back(i);
			dfs(cnt + 1);
			v.pop_back();
			visit[i] = 0;
		}
	}
}

int main() {
	cin >> N >> M;
	dfs(1);
}