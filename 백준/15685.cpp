#include <iostream>
#include <vector>
using namespace std;

int N;
int X, Y, D, G;
int map[100][100];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
vector<int> dir;
int cnt;

void DragonCurve() {
	int size = dir.size();
	for (int i = size-1; i >=0; i--){
		int nextdir = (dir[i] + 1) % 4;
		Y += dx[nextdir];
		X += dy[nextdir];
		map[Y][X] = 1;
		dir.push_back(nextdir);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> X >> Y >> D >> G;
		dir.clear();

		map[Y][X] = 1;
		Y += dx[D];
		X += dy[D];
		map[Y][X] = 1;
		dir.push_back(D);
		
		while (G--) DragonCurve();
	}
	for (int i = 0; i < 99; i++){
		for (int j = 0; j < 99; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j+1] && map[i+1][j+1]) {
				cnt++;
			}
		}
	}

	cout << cnt << endl;
}