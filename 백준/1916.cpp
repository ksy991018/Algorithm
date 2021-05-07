#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>>v[1000];
int mincost[1001];
int INF = 1000000000;
int city, bus; //���� , ����

void dijkstra(int start) {
	mincost[start] = 0;
	priority_queue<pair<int, int> > pq; //�� ����(�ִ��� : ū ���� �������� �ֻ�ܳ�带 ����)
	//����� ������� ó���ϹǷ� ť�� ���
	pq.push(make_pair(start, 0));
	while (!pq.empty()) {
		int current = pq.top().first; //pq�� �ֻ�� ��忡 �ִ� ù��°���� ����湮
		//ť�� �������� ���� ��������� ������ ����� ������ �������
		//ª������ ���� ������ ����ȭ(-) ��Ŵ
		int distance = -pq.top().second;
		pq.pop(); //queue���� �ϳ��� ����
		if (mincost[current] < distance) continue; //�ִܰŸ��� �ƴѰ�� ��ŵ
		for (int i = 0; i < v[current].size(); i++) {
			//���õ� ����� �������
			int next = v[current][i].first;
			//���õ� ��� ���ļ� �������� ���� ���
			int nextdistance = distance + v[current][i].second;
			//������ �ּҺ�뺸�� �� �����ϴٸ� ��ü
			if (nextdistance < mincost[next]) {
				mincost[next] = nextdistance;
				pq.push(make_pair(next, -nextdistance)); //����ȭ
			}
		}
	}
}

int main() {

	cin >> city >> bus;

	for (int i = 1; i <= city; i++){
		mincost[i] = INF;
	}

	int a, b, cost;
	for (int i = 0; i < bus; i++){
		cin >> a >> b >> cost;
		v[a].push_back(make_pair(b, cost));
	}

	int start, end;
	cin >> start >> end;
	
	dijkstra(start);

	cout << mincost[end];

}