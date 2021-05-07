#include <iostream>
#include <queue>
using namespace std;

int visit[100001]; //�湮�ߴ��� üũ
int c[100001] = { 0, }; //���° �ð����� ����
int N,K;
queue<int> q;

bool check(int index) { //�ε��� �����˻�
	if (index >= 0 && index <= 100000) return true;
	return false;
}

void bfs() {
	bool flag = true;
	while (!q.empty() && flag) {
		int cur = q.front();
		q.pop();
		int dx[3] = { cur - 1,cur + 1,cur * 2 };
		for (int i = 0; i < 3; i++){
			if (check(dx[i]) && !visit[dx[i]]) {
				visit[dx[i]] = 1;
				c[dx[i]] = c[cur]+1; //����Ʈ
				if (dx[i] == K) flag = false; //����ã���� �������
				q.push(dx[i]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	if (N == K) cout << 0;
	else {
		q.push(N);
		visit[N] = 1;
		bfs();
		cout << c[K];
	}
}