#include <iostream>
#include <queue>
using namespace std;

struct Node {
public:
	int mass; //질량 
	int dir; //방향
	int speed; //속도
	Node(int mass, int speed, int dir) {
		this->mass = mass;
		this->speed = speed;
		this->dir = dir;
	}
};

int N, M, K;
int r, c, m, s, d;
queue<Node> map[51][51];
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int newDir[8] = { 0,2,4,6,1,3,5,7 };
int result;



int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		cin >> r >> c >> m >> s >> d;
		map[r][c].push(Node(m, s, d));
	}

	while (K--) {
		result = 0;
		queue<Node> map_cp[51][51];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!map[i][j].empty()) {
					int size = map[i][j].size();
					for (int k = 0; k < size; k++) {
						Node cur = map[i][j].front();
						map[i][j].pop();
						int cx=i, cy=j;
						for (int t = 0; t < cur.speed; t++) {
							cx+=dx[cur.dir];
							cy+= dy[cur.dir];
							if (cx <= 0) cx += N;
							else if (cx > N) cx -= N;
							if (cy <= 0) cy += N;
							else if (cy > N) cy -= N;
						}
						map_cp[cx][cy].push(cur);
					}
				}
			}
		}
		for (int i = 1; i <= N; i++) {//복사
			for (int j = 1; j <= N; j++) {
				if (!map_cp[i][j].empty()) {
					int size = map_cp[i][j].size();
					while (size--) {
						map[i][j].push(map_cp[i][j].front());
						map_cp[i][j].pop();
					}
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j].size() >= 2) {
					int Msum = 0;
					int Ssum = 0;
					bool flag = true; //모두 홀수 or 짝수 
					int dir = -1;
					int cnt = map[i][j].size();
					for (int k = 0; k < cnt; k++) {
						Node cur = map[i][j].front();
						map[i][j].pop();
						Msum += cur.mass;
						Ssum += cur.speed;
						if (k == 0) dir = cur.dir % 2;
						else if (flag) {
							if (cur.dir % 2 != dir) flag = false;
						}
					}
					if (Msum / 5 == 0) continue;
					int start = -1;
					if (flag) start = 0; //모두 홀수나 짝수면
					else start = 4;
					for (int k = start; k < start + 4; k++) {
						map_cp[i][j].push(Node(Msum / 5, Ssum / cnt, newDir[k]));
						result += Msum / 5;
					}
				}
				else if (map[i][j].size() == 1) {
					result += map[i][j].front().mass;
					map_cp[i][j].push(map[i][j].front());
					map[i][j].pop();
					
				}
			}
		}
		for (int i = 1; i <= N; i++) {//복사
			for (int j = 1; j <= N; j++) {
				if (!map_cp[i][j].empty()) {
					int size = map_cp[i][j].size();
					while (size--) {
						map[i][j].push(map_cp[i][j].front());
						map_cp[i][j].pop();
					}
				}
			}
		}

	}
	cout << result << endl;

}