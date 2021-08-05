#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M,a,b;
vector<int> map[10001];
bool visit[10001];
int best; //������� ��ŷ������ �ִ�
int tmp;

//������ķ� Ǯ�� �ð��ʰ�. 

void dfs(int cur) {
	visit[cur] = 1;
	for (int i = 0; i < map[cur].size(); i++) {
		int next = map[cur][i];
		if (!visit[next]) {
			tmp++;
			dfs(next);
		}
	}
	//���۳�� �������� ���� ��찡 ���͵� �� ��쿡 ���� ������ ī��Ʈ�ؼ� �ִ��̶� ���� �ʿ����.
	//�Ű�������(int cur, int cnt)���ϰ�  tmp=max(tmp,cnt) �� �ϸ� �ð��ʰ�. 
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[b].push_back(a); //�ܹ��� �׷���
	}

	vector<int> result;
	for (int i = 1; i <= N; i++) {
		tmp = 0; //���� ��ǻ�Ϳ��� ��ŷ�Ҽ��ִ� �ִ��
		memset(visit, 0, sizeof(visit));
		dfs(i);
		if (best <= tmp) {
			if (best < tmp) {
				result.clear();
				best = tmp;
			}
			result.push_back(i);
		}
	}
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;

	return 0;
}