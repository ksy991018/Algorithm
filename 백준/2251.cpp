#include <iostream>
#include <queue>
using namespace std;

int visit[201][201]; //[ù��°����][�ι�°����]
int from[6] = { 0,0,1,1,2,2 }; //�� ������ ��� 6���� : From[i] -> To[i]
int to[6] = { 1,2,0,2,0,1 };
int result[201]; //����° ������ ���� ��
int bottle[3]; //������ ����
queue<pair<int, int>> q;

int main() {
	for (int i = 0; i < 3; i++) {
		cin >> bottle[i];
	}

	//�� ó�� ���̽�
	result[bottle[2]] = 1;
	visit[0][0] = 1;
	q.push({ 0,0 });

	//bfs
	while (!q.empty()) {
		int one = q.front().first;
		int two = q.front().second;
		int three = bottle[2] - one - two; //������ ���� ��
		q.pop();
		for (int i = 0; i < 6; i++){
			int cur[3] = { one,two,three };//�� ������ ����

			cur[to[i]] += cur[from[i]]; //�� �ױ�
			cur[from[i]] = 0;
			if (cur[to[i]] > bottle[to[i]]) { //���� ��ģ ���
				cur[from[i]] = cur[to[i]] - bottle[to[i]];
				cur[to[i]] = bottle[to[i]];
			}
			if (!visit[cur[0]][cur[1]]) { //���ο� �� ������ ���
				visit[cur[0]][cur[1]] = 1;
				q.push({ cur[0],cur[1] });
				if (cur[0] == 0) { //ù��° ���� �� ���
					result[cur[2]] = 1; //����° ���� ��
				}
			}
		}
	}
	for (int i = 0; i <= bottle[2]; i++) {
		if(result[i]) cout << i << " ";
	}
}