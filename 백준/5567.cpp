#include <iostream>
#include <vector>
using namespace std;

int N, M;
int visit[501]; //�ʴ뿩��
int cnt; //�ʴ��� �����
vector<int> v[501]; //ģ�� ���� �׷���
vector<int> f; //����� ģ��

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) { 
			visit[b] = 1;
			f.push_back(b);
			cnt++;
		}
		else if (b == 1) {
			visit[a] = 1;
			f.push_back(a);
			cnt++;
		}
		else { //ģ���� ģ�����踸 ���
			v[a].push_back(b);
			v[b].push_back(a);
		}
	}

	for (int i = 0; i < f.size(); i++) { //����� ģ������ ���踸 Ž��
		int cur = f[i];
		for (int j = 0; j < v[cur].size(); j++) {
			int next = v[cur][j];
			if (!visit[next]) {
				visit[next] = 1;
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}