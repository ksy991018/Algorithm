#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> c;
vector<char> tmp;
int visit[26];

//��Ʈ��ŷ 
void solve(int cur,int cnt) { //���ĵ� ������ �����ϵ� �ߺ����� �����ϱ� ���� �ΰ��� �Ű����� ���(������ġ,���ð���)
	if (cnt == L) {
		int cnt = 0;
		string s = "";
		for (int i = 0; i < L; i++){
			if (tmp[i] == 'a' || tmp[i] == 'e' || tmp[i] == 'i' || tmp[i] == 'o' || tmp[i] == 'u') cnt++;
			s.push_back(tmp[i]);
		}
		if (1 <= cnt && L - cnt >= 2) cout << s << endl; //���� 1���̻� & ���� 2���̻�
		return;
	}
	for (int i = cur; i < C; i++) {
		int index = c[i] - 'a';
		if (!visit[index]) {
			visit[index] = 1;
			tmp.push_back(c[i]);
			solve(i+1,cnt + 1);
			tmp.pop_back();
			visit[index] = 0;
		}
	}
}

int main() {
	cin >> L >> C;
	char n;
	for (int i = 0; i < C; i++) {
		cin >> n;
		c.push_back(n);
	}
	sort(c.begin(), c.end()); //�� ����
	solve(0,0);
}