#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, S, M;
int n;
int v[1001]; //현재 턴에 가능한 볼륨은 1
int v_cp[1001];

int main() {
	cin >> N >> S >> M;
	v[S] = 1;
	for (int i = 0; i < N; i++) {
		cin >> n;
		memset(v_cp, 0, sizeof(v_cp));

		for (int j = 0; j <= M; j++){
			if (v[j]) {
				if (j + n <= M) v_cp[j + n] = 1; 
				if (j - n >=0) v_cp[j - n] = 1;
			}
		}
		copy(v_cp, v_cp + M+1, v);

	}
	for (int i = M; i >=0; i--){ //큰수부터
		if (v[i]) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}