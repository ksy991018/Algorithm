#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int N, K; //���� ũ��, �������
int D; //���� ��ȯ��
int map[101][101];
int dx[4] = { 0,1,0,-1 }; //��,��,��,��  D(������)�� +1 C(����)�� -1
int dy[4] = { 1,0,-1,0 };
int cnt; //���� ��
queue<pair<int, char>> change; //���� ��ȯ
deque<pair<int, int>> snake; //�� (iterator ������ deque��)

bool check(int x, int y) {
	if (x <= 0 || x > N || y <= 0 || y > N) return false;
	for (auto i = snake.begin(); i < snake.end(); i++){ //�ڽ��̶� �ε������� Ȯ��
		if (i->first == x && i->second == y) return false;
	}
	return true;
}

void solve(int dir,pair<int,int> cur) {

	if (!change.empty()) {//���� ��ȯ Ÿ������
		pair<int, char> tmp = change.front();
		if (tmp.first == cnt) { //���� ���� & ����
			change.pop(); 
			if (tmp.second == 'D') {
				if (dir + 1 == 4) dir = -1; //����
				solve(dir + 1, cur);
				return;
			}
			if (tmp.second == 'L') {
				if (dir - 1 == -1) dir = 4; //����
				solve(dir - 1, cur);
				return;
			}
		}
	}
	cnt++; //�ð��߰�
	int x = cur.first + dx[dir]; //�̵��� ��ǥ
	int y = cur.second + dy[dir];

	if (!check(x, y)) return; //�̵��ϰ��� �ϴ� ��ǥüũ

	snake.push_back({ x,y });
	if (!map[x][y]) { //������ٸ�
		snake.pop_front();//��������
		solve(dir, { x,y });
	}
	else {//����ִٸ�
		map[x][y] = 0; //�������
		solve(dir, { x,y });
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++){
		int a, b;
		cin >> a >> b;
		map[a][b] = 1; //���ǥ��
	}
	cin >> D;
	for (int i = 0; i <D ; i++){
		int c;
		char d;
		cin >> c >> d;
		change.push({ c,d }); //�����߰�
	}

	snake.push_back({ 1,1 }); 
	solve(0,{ 1,1 }); //���� & �����ġ
	cout << cnt;
}