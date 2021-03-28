#include <iostream>
#include <algorithm>
#define INF 10000000
using namespace std;

int N, M, H; //���μ�,���μ�,���μ���ġ��
int visit[31][11]; //[a][b] --->  b & b+1���μ� ���̸� a�� ���μ��� ����
int result=INF;

bool check() { //I�� ���μ� ����� I������ �׽�Ʈ 
	for (int i = 1; i <= N; i++) {
		int curr = i; //���� ���μ� 
		for (int j = 1; j <= H; j++) {
			if (visit[j][curr]) curr++; //��
			else if(visit[j][curr-1]) curr--; //��
		}
		if (curr != i) return false; 
	}
	return true;
}

void solve(int idx, int cnt) { //idx : ���μ�
	if (cnt > 3) return;

	if (check()) {
		result = min(result, cnt);
		return;
	}
	for (int i = idx; i <= H; i++) {
		for (int j =1; j <= N; j++) {
			if (!visit[i][j + 1] && !visit[i][j - 1] && !visit[i][j]) { //���μ� ���� x
				visit[i][j] = 1;
				solve(i, cnt + 1);
				visit[i][j] = 0;
			}
			
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> H;
	for (int i = 0; i < M; i++){ //�̸� ���μ�����
		int a, b;
		cin >> a >> b;
		visit[a][b] = 1;
	}
	solve(1, 0);
	cout << (result == INF ? -1 : result);
}