#include <iostream>
using namespace std;

int N,B,C;
int n[1000000];
long long cnt;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}
	cin >> B >> C;
	cnt = N;
	for (int i = 0; i < N; i++){
		n[i] -= B;
		if (n[i] > 0) {
			if (n[i] % C != 0) cnt += (n[i] / C + 1);
			else cnt += n[i] / C;
		}
	}
	cout << cnt << endl;
}