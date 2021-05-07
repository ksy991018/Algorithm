#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K; //��ũ��, ��� , ���� �����ð�
int map[20][20];

int time; //���
int live; //����ִ� ���
int dx[5] = {0, -1,1,0,0 };
int dy[5] = {0, 0,0,-1,1 };
vector<pair<int, pair<int, int>>> newLoc; //�� �� ������ <���°���,<�̵��� ��ġ>>

struct smell { //����
	int num; //����
	int remain; //���� �ð�
};
smell s[20][20];

struct shark {
	int num;
	int x;
	int y;
	int dir; //1:��,2:�Ʒ�,3:����,4:������
	int priority[4][4]; //��,�Ʒ�,����,������
	bool safe = true;
};

shark fish[401];

void Decrease() { //�������̱�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (s[i][j].remain != 0) s[i][j].remain--;
			if (s[i][j].remain == 0) s[i][j].num = 0; //���� �پ������� 
		}
	}
}

bool check(int num, int move) { //����� �̵� ���ɿ���
	int cx = fish[num].x + dx[move];
	int cy = fish[num].y + dy[move];
	if (cx >= 0 && cx < N && cy >= 0 && cy < N) {
		if (s[cx][cy].num == 0 && s[cx][cy].remain == 0) return true;
	}
	return false;
}


void solve() {
	while (live > 1 && time <=1000) {
		newLoc.clear();
		for (int i = M; i >= 1; i--){
			if (!fish[i].safe) continue;
			bool success = false;
			for (int j = 0; j< 4; j++){ //�ƹ����� ���� ĭ ����
				int want = fish[i].priority[fish[i].dir-1][j]; //���� ������� �켱 �̵�����

				if (check(i, want)) {
					success = true; //ĭ�̵� ����
					fish[i].x += dx[want];
					fish[i].y += dy[want];		
					fish[i].dir = want;
					newLoc.push_back({ i, {fish[i].x,fish[i].y} }); //�̵��� ��ġ ����
					break;
				}
			}
			if (!success) { //ĭ �̵����� �������� �ڱ⳿�� �������� �̵�
				for (int j = 0; j < 4; j++) {
					int want = fish[i].priority[fish[i].dir-1][j]; //���� ������� �켱 �̵�����
					int cx = fish[i].x + dx[want];
					int cy = fish[i].y + dy[want];
					if (cx >= 0 && cx < N && cy >= 0 && cy < N) {
						if (s[cx][cy].num == i) { //�ڱ� ������
							fish[i].x =cx;
							fish[i].y = cy;
							fish[i].dir = want;
							newLoc.push_back({ i, {cx,cy} }); //�̵��� ��ġ ����
							break;
						}
					}
				}
			}
		}
		Decrease(); //�������̱�
		sort(newLoc.begin(), newLoc.end()); //����ȣ ū�ͺ��� �Ϸ���
		for (int i = newLoc.size()-1; i >=0; i--) { //����̵� 
			auto tmp = newLoc[i];
			auto go =s[tmp.second.first][tmp.second.second];
			if (go.remain == K) { //��ȣ ū��� ����̵��ߴµ� �� ���� ��� �̵��Ҷ� 
				fish[go.num].safe = false; //��Ƹ���
				live--;
			}
			s[tmp.second.first][tmp.second.second] = { tmp.first,K}; //��ġ����
		}
		time++;
	}
}

int main() {
	cin >> N >> M >> K;
	live = M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;
			if (n!= 0) { //��� ��ġ,���� ǥ��
				s[i][j] = { n,K };
				fish[n].x = i;
				fish[n].y = j;
			}
		}
	}

	for (int i = 1; i <= M; i++){ //��� ����ǥ�� 
		fish[i].num = i;
		cin >> fish[i].dir;
	}

	for (int i = 1; i <= M; i++){ //��� �켱����
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> fish[i].priority[j][k];
			}
		}
	}

	solve();
	cout << (time>1000? -1 : time);
}