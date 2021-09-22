#include <iostream>
using namespace std;

int N, M;
int a[10001];
int cnt = 0;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}

	int start = 0, end = 0,tmp=0;

	while (end<=N) {
		if (tmp == M) cnt++;

		if (tmp >= M) {
			tmp -= a[++start];
		}
			
		else tmp += a[++end];

	}
	cout << cnt << endl;
}
