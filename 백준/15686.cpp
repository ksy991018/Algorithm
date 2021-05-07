#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//�Ｚ ����
//���Ʈ���� ��üŽ��
int N, M; //����ũ��, ġŲ�� �ִ��
int map[50][50];
int visit[13]; //ġŲ�� ���ÿ���
vector<pair<int, int>> house; //�� ��ǥ
vector<pair<int, int>> chicken; //ġŲ�� ��ǥ
priority_queue<int,vector<int>,greater<int>> pq; //�ּڰ� ���

int distance(pair<int, int>a, pair<int, int>b) { //�Ÿ����
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int cur, int cnt) { //cur : ���� ����� ġŲ�� �ε��� / cnt : ������� ������ ġŲ�� ��
	if (cnt == M) { //ġŲ�� �ٰ������
		int result = 0;
		for (int i = 0; i < house.size(); i++) { //��� ���� ����
			int tmp = 1000000;
			for (int j = 0; j < chicken.size(); j++) {//������ ġŲ����� �Ÿ��� �ּҰŸ� 
				if (visit[j]) tmp = min(tmp,distance(chicken[j], house[i]));
			}
			result += tmp;
		}
		pq.push(result);
		return;
	}
	if (cur == chicken.size()) return; //ġŲ�� ���̻� x
	visit[cur] = 1; //��Ʈ��ŷ
	dfs(cur + 1, cnt + 1);
	visit[cur] = 0;
	dfs(cur + 1, cnt);
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) house.push_back({ i,j });
			if (map[i][j] == 2) chicken.push_back({ i,j });
		}
	}
	dfs(0, 0);
	cout << pq.top(); //�ּڰ� ���
}