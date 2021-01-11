#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#define MAX 32001
using namespace std;

//��������: ������ �������ִ� �۾��� ���ʷ� �����ؾ��Ҷ� ���� �������ִ� �˰���
//��Ģ�� ��Ű�鼭 �����ϸ� ���� ���ں��� ����ؾ��ϱ� ������ �켱���� ť ���.
priority_queue<int, vector<int>, greater<int>> pq; //�������� : �������ں��� ���
int N, n;
int inDegree[MAX];
vector<int> v[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> n;
	for (int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b); //�׷��� �׸��� 
		inDegree[b]++; //���� �߰�
	}

	for (int i = 1; i <=N ; i++){
		if (inDegree[i] == 0) { //�������� 0�� ��带 ť�� ����
			pq.push(i);
		}
	}

	while(!pq.empty()){
		int x = pq.top();
		pq.pop();
		cout << x << " ";
		for (int i = 0; i < v[x].size(); i++){ //pop�� ���� ����� ������ ������ ����.
			int tmp = v[x][i];
			if (--inDegree[tmp] == 0) { //���Ӱ� �������� 0�� ��� ť ����
				pq.push(tmp);
			}
		}
	}
}