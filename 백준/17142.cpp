#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int map[50][50]; //0:��ĭ, 1:��, 2: ���̷���
int visit[50][50];
int minTime = 987654321;//���̷��� ��� ������ �ּҽð�
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<pair<int,int>> v; //���̷��� ��ġ
vector<pair<int, int>> tmp; //Ȱ��ȭ ���̷��� ��ġ
int tmpvisit[10]; //��Ʈ��ŷ
int blank; //��ĭ �� <- �ð��ʰ������� ���


void SpreadVirus() { //Ȱ��ȭ ���̷��� �۶߸���
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> q;
	for (int i = 0; i < tmp.size(); i++){ //Ȱ��ȭ ���̷���
		q.push(tmp[i]);
		visit[tmp[i].first][tmp[i].second] = 1;
	}
	int cnt = 0; //���� �ð�
	int blankcnt = 0; //���̷����� ���� ��ĭ�� �� <- �ð��ʰ� ����

	while (!q.empty() && blankcnt<blank) { //bfs
		int size = q.size();
		cnt++; 
		while(size--){		
			int x = q.front().first;
			int y = q.front().second;
			q.pop(); 		
			for (int i = 0; i < 4; i++){
				int cx = x + dx[i];
				int cy = y + dy[i];
				if (cx >= 0 && cx < N && cy >= 0 && cy < N && !visit[cx][cy] && map[cx][cy] != 1) {//����o,�湮x,��x
					if(map[cx][cy]==0) blankcnt++; //��ĭ�ε� ���̷��� ������� <- ��Ȱ��ȭ ���̷��� ĭ�̶� ��������
					visit[cx][cy] = 1;
					q.push({ cx,cy });
				}
			}
		}
	}
	if (blankcnt == blank) minTime = min(minTime, cnt);
}

void Activate(int cur) { //Ȱ��ȭ ���̷��� M�� ���� : ��Ʈ��ŷ
	if (tmp.size() == M) {
		SpreadVirus();
		return;
	}
	if (cur >= v.size()) return;
	for (int i = cur; i < v.size(); i++){
		if (!tmpvisit[i]) {
			tmpvisit[i] = 1;
			tmp.push_back(v[i]);
			Activate(i + 1);
			tmp.pop_back();
			tmpvisit[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	bool noVirus = true; //���̷��� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) v.push_back({ i,j }); //���̷���
			if (map[i][j] == 0) { //��ĭ
				blank++;
				noVirus = false;
			}
		}
	}
	if (!noVirus) Activate(0); //���̷��� ������
	else minTime = 0; //���̷��� ������
	cout << (minTime==987654321? -1 : minTime) << endl;
}