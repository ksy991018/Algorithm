#include <iostream>
using namespace std;

int T, N, M;
int result[30][30];

int calc(int n, int c) { //�Ľ�Į �ﰢ��
	if (n == c || c == 0) return 1;
	if (c == 1) return n;

	if (result[n][c] == 0) result[n][c] = calc(n - 1, c - 1) + calc(n - 1, c); //������������� �״�� ���. �̰žȾ��� �ð��ʰ�
	return result[n][c];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		cout << calc(M, N) << "\n";
	}
}