#include <iostream>
#include <limits.h>
#include <algorithm>
#include <cstring>
using namespace std;

int T, n, m;
int a, b, p, q;
int win[1001];
int lose[1001];

int main() {
	cin >> T;
	while (T--) {
		memset(win, 0, sizeof(win));
		memset(lose, 0, sizeof(lose));
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> p >> q;
			win[a] += p; win[b] += q;
			lose[a] += q; lose[b] += p;
		}
		int minV = INT_MAX;
		int maxV = 0;
		for (int i = 1; i <=n ; i++){
			double exp;
			if (win[i] == 0 && lose[i] == 0) exp = 0;
			else {
				exp = (double)win[i] * win[i] / (win[i] * win[i] + lose[i] * lose[i]);
			}
			exp *= 1000;
			maxV = max(maxV, (int)exp);
			minV = min(minV, (int)exp);
		}
		cout << maxV << endl; cout << minV << endl;
	}
}