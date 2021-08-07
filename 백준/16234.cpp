#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, L, R;
int map[50][50];
int visit[50][50];
int cnt;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> tmp; //���漱 �����ϴ� ����� 

bool isInside(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < N) return true;
	else return false;
}

int bfs(int a, int b) {
	queue<pair<int, int>> q;
	int sum = 0; //������ �� �α���

	q.push({ a, b });
	tmp.push_back({ a,b });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		sum += map[x][y];

		for (int i = 0; i < 4; i++) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (isInside(cx, cy)) {
				int diff = abs(map[x][y] - map[cx][cy]);
				if (diff >= L && diff <= R) { //�α��� �������� ������ 
					if (!visit[cx][cy]) {
						visit[cx][cy] = 1;
						q.push({ cx,cy }); 
						tmp.push_back({ cx,cy }); //���漱 �������� ��ġ
					}
				}
			}
			
		}
	}
	if (sum>map[a][b]) return sum;
	else {
		tmp.clear();
		return 0;
	}
}
int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	while (true) {
		memset(visit, 0, sizeof(visit)); 
		bool flag = false; //�̹��Ͽ� �α��̵� ����
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j]) { //�̹� �ٳణ �� or �α� �̵� �Ͼ �� ���� Ž��
					tmp.clear(); 
					int value = 0;
					visit[i][j] = 1;
					int result = bfs(i, j);
					if (result != 0) { //�����ϴ� ���� ������ ��
						flag = true;
						value = result / tmp.size();
					}
					for (int i = 0; i < tmp.size(); i++){ //���漱 �������� ��ϰ� ������Ʈ
						map[tmp[i].first][tmp[i].second]= value;
					}				
				}
			}
		}
		if (flag) cnt++;
		else break;
	}
	cout << cnt << endl;
}