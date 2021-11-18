#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int N;
string start, target;
int cnt;

void swap(string& s, int i) {//i��° ����ġ ������
	for (int j = i - 1; j <= i + 1; j++) {
		if (j < 0 || j >= N) continue;
		if (s[j] == '1') s[j] = '0';
		else s[j] = '1';
	}
}

int solve(string a, bool include) {
	int tmpcnt = 0;
	if (include) { //ó�� 0��° ���� �ٲٰ� �����ϴ� ���
		swap(a, 0);
		tmpcnt++;
	}
	for (int i = 1; i < N; i++) {//1��°~N-1��° ���� �ٲٱ�
		if (a[i - 1] != target[i - 1]) {//i-1��° ������ �����ִ°� i�� ����ġ�� 
			swap(a, i);
			tmpcnt++;
		}
	}
	if (a == target) return tmpcnt; //������� �ϴ� �����϶� 
	else return INF;

}

int main() {
	cin >> N;
	cin >> start >> target;

	cnt = min(solve(start, true),solve(start,false));//0��° ���� ������ �ȴ����� 2���� ���̽� 
	cout << (cnt == INF ? -1 : cnt) << endl;
}
