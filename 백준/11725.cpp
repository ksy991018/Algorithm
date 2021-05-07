#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v[100001];
int visit[100001];
int result[100001];

void dfs(int parent) {
	visit[parent] = 1;

	for (int i = 0; i <v[parent].size(); i++){
		int child = v[parent][i];
		if (!visit[child]) {
			result[child] = parent;
			dfs(child);
		}		
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N-1; i++)	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);
	for (int i = 2; i <=N; i++){
		cout << result[i] << "\n";
	}
}




//이렇게 풀면 부모 모르는 상황일때 반례생김 
//#include <iostream>
//#include <vector>
//using namespace std;

//int N;
//int parent[100001] = { 0,1 };
//
//int main() {
//
//	cin >> N;
//	for (int i = 0; i < N-1; i++)	{
//		int a, b;
//		cin >> a >> b;
//		if (parent[a] == 0) parent[a] = b;
//		else parent[b] = a;
//	}
//	for (int i = 2; i <= N; i++){
//		cout << parent[i] << "\n";
//	}
//}