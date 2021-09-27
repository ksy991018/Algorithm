#include <iostream>
#include <string>
using namespace std;

int N;
string result;
bool finish = false;

void solve(string tmp,int cnt) {
	if (finish ) return;
	int size = tmp.size();
	for (int i = 1; i <= size / 2; i++) {//규칙검사
		if (tmp.substr(size - i, i) == tmp.substr(size - 2 * i, i)) return;
	}
	if (cnt == N) {
		result = tmp;
		finish = true;
	}
	for (int i = 0; i < N; i++) {//백트래킹
		solve(tmp + "1", cnt + 1);
		solve(tmp + "2", cnt + 1);
		solve(tmp + "3", cnt + 1);
	}
}

int main() {
	cin >> N;
	solve("",0);
	cout << result << endl;
}