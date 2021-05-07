#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int slot[52][52];
void checking(int a, int b) {
	slot[a][b] = 0;
	if (slot[a - 1][b] == 1) {
		checking(a - 1, b);
	}
	if (slot[a][b - 1] == 1) {
		checking(a, b - 1);
	}
	if (slot[a + 1][b] == 1) {
		checking(a + 1, b);
	}
	if (slot[a][b + 1] == 1) {
		checking(a, b + 1);
	}
}
int main()
{
	int T;
	int M, N;
	int K;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int ans = 0;
		// Ä­ ÃÊ±âÈ­
		for (int j = 0; j < 52; j++) {
			for (int k = 0; k < 52; k++) {
				slot[j][k] = 0;
			}
		}
		cin >> M >> N >> K;
		// Ä­ ÀÔ·Â
		for (int j = 0; j < K; j++) {
			int x, y;
			cin >> x >> y;
			x++; y++;
			slot[x][y] = 1;
		}
		for (int j = 1; j <= M; j++) {
			for (int k = 1; k <= N; k++) {
				if (slot[j][k] == 1) {
					ans++;
					checking(j, k);
				}
			}
		}
		cout << ans << endl;
	}
}