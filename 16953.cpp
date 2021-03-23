#include <iostream>
#include <algorithm>
using namespace std;

long long A, B;
int result;

void solve(long long n, int cnt) {
	if (n > B) return;
	if (n == B) {
		result = max(result, cnt);
		return;
	}
	solve(n *2,cnt+1); //2��
	solve(n * 10 + 1,cnt+1); //�ڿ� 1�߰�
}

int main() {
	cin >> A >> B;
	solve(A,1);
	cout << (result == 0 ? -1 : result);
}