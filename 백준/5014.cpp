#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int n[1000001];
int visit[1000001];
queue<int> q;

int main() {
	cin >> F >> S >> G >> U >> D;

	q.push(S);
	visit[S] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int next;
		for (int i = 0; i < 2; i++) {
			if (i == 0) next = cur + U; //위
			else next = cur - D; //아래

			if (next>=1 && next<=F && !visit[next]) { //visit먼저 검사하면 OutOfBound
				visit[next] = 1;
				n[next] = n[cur] + 1;
				q.push(next);
			}
		}	
	}

	if (S!=G && n[G] == 0) { //지나가지 못했거나 시작출발점이 다르면
		cout << "use the stairs";
	}
	else {
		cout << n[G];
	}

}