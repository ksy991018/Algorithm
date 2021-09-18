#include <iostream>
#include <queue>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
int map[12][12];
deque<int> horse[12][12]; //��ǥ���� �׿��ִ� ������ ��ȣ ���̼� ����
vector<pair<pair<int, int>,int>> v; // ������ ���� ����, �ε��� : ����ȣ, �� : <<x,y>,����>
int turn;

int main() {
	cin >> N >> K;
	for (int i = 0; i < N ; i++){
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int x, y, dir;
	for (int i = 0; i < K; i++){
		cin >> x >> y >> dir;
		horse[x - 1][y - 1].push_back(i);
		v.push_back({ {x-1,y-1},dir });
	}
	bool exit = false; //�� 4���̻� ����
	while (!exit && turn <= 1000) {
		turn++; //�� ����
		for (int i = 0; i < K; i++){//��� ���� ���� ����
			int x = v[i].first.first;
			int y = v[i].first.second;
			int dir = v[i].second;
			int cx = x + dx[dir];
			int cy = y + dy[dir];
			if (cx < 0 || cx >= N || cy < 0 || cy >= N || map[cx][cy]==2) {//������ or �Ķ� -> ����ٲٱ�
				if (dir == 1) dir = 2;
				else if (dir == 2) dir = 1;
				else if (dir == 3) dir = 4;
				else dir = 3;
				cx = x + dx[dir];
				cy = y + dy[dir];
				v[i].second = dir; //���� �ٲٱ�
			}
			if (cx >= 0 && cx < N && cy >= 0 && cy < N) { //���� ��
				if (map[cx][cy] == 0 || map[cx][cy]==1) {//��� or ������ , �Ķ����� ��� �ƹ��͵� ����
					vector<int> tmphorse; //�ӽ� ���� <- reverse��� ���� ���� ����
					int size = horse[x][y].size();
					bool flag = false; //���� �ű� �������� ����
					for (int j = 0; j < size; j++) {//�ش� ������ �����ִ°ű��� ��� �ű��
						int tmp = horse[x][y][0]; //���� Ž���� ��
						horse[x][y].pop_front();
						if (flag || tmp == i) {//�ش縻�̰ų� �ش縻 ���������� �ű��
							flag = true; 					
							tmphorse.push_back(tmp);
							v[tmp].first.first = cx;
							v[tmp].first.second = cy; //�� ��ġ���� ������Ʈ
						}else {					
							horse[x][y].push_back(tmp); //�ȿű�� ������ǥ�� �ٽóֱ�
						}
					}
					if (map[cx][cy] == 1) reverse(tmphorse.begin(), tmphorse.end()); //�����̸� �����ݴ��
					for (int k = 0; k < tmphorse.size(); k++){ //���������� �ű��
						horse[cx][cy].push_back(tmphorse[k]);
					}
					if (horse[cx][cy].size() >= 4) {//4���̻� ���̸�
						exit = true;
						break;
					}
				}
			}
		}

	}
	cout << (turn>1000? -1 : turn) << endl;
}