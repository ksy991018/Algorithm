#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N;
int map[21][21];
vector<pair<int,pair<int, int>>> fish; //����� <ũ��,<��ġ>>
int Ssize = 2; //�Ʊ��� ũ��
int sharkX, sharkY; //�����ġ
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int time; //�ð� (��°�)
int eat; //��� �Ծ����� (������ ������ ���ؼ�)
int visit[21][21];

int bfs(int x1, int y1,int x2,int y2) { //(x1,y1)���� (x2,y2)���� �Ÿ� ���
	memset(visit, 0, sizeof(visit));
	queue<pair<int,pair<int, int>>> q; //<�ð�,<��ǥ>>
	q.push({ 0,{ x1, y1 } });
	visit[x1][y1] = 1;
	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int tmpTime = q.front().first;
		q.pop();
		
		for (int i = 0; i < 4; i++){
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx > 0 && cx <= N && cy > 0 && cy <= N && map[cx][cy] <= Ssize && !visit[cx][cy]) { 
				if (cx == x2 && cy == y2) return time+1;
				q.push({tmpTime + 1,{cx, cy}});
				visit[cx][cy] = 1;
			}
		}
	}
	return 0;
}

void solve() {	
	while (true) {
		int result = 1000000;
		int targetFish = -1;
		//���� ���� ����� 1���� ����
		for (int i = 0; i < fish.size(); i++) { 
			if (fish[i].first < Ssize) { //������ �ִ� ������� (������ ���� ����� ��)
				int tmp = bfs(sharkX, sharkY, fish[i].second.first, fish[i].second.second); //�Ÿ����
				if (tmp>0 && result > tmp) { //���� ����� �����. �Ÿ� ���� ��쵵 ���� ���Ȱ� �켱����.
					targetFish = i;
					result = tmp;
				}
			}
		}
		if (targetFish == -1 || fish.size()==0) break; //������ �ִ� ����� ������ 
		eat++; //����� ����
		if (eat == Ssize) { //�����ŭ ������ ������
			Ssize++;
			eat = 0;
		}
			
		time += result; //�Ÿ��� �ð� �����ϹǷ� 
		
		sharkX = fish[targetFish].second.first; //��� ��Ƹ��� ������� ��ġ�� ��� �̵�
		sharkY = fish[targetFish].second.second;
		fish.erase(fish.begin() + targetFish); //���� ����� ����
		map[sharkX][sharkY] = 0; //���� ����� ������ ����� 
	}	
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] <= 6) {
				fish.push_back({ map[i][j],{i,j} }); 
				//���� �ǿ��ʺ��� ����� �ֱ⶧����, ���� �Ÿ� ������ �������� �켱���� ���� ������ �ʿ����. �տ� �ε������� ����ϸ� ��.

			}
			if (map[i][j] == 9) {
				sharkX = i;
				sharkY = j;
				map[i][j] = 0; //��� ��ġ ǥ������ 0����
			}
		}
	}
	solve();
	cout << time; //������� �ð�
}