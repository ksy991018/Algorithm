#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>>v[1000];
int mincost[1001];
int INF = 1000000000;
int city, bus; //정점 , 간선

void dijkstra(int start) {
	mincost[start] = 0;
	priority_queue<pair<int, int> > pq; //힙 구조(최대힙 : 큰 값을 기준으로 최상단노드를 만듬)
	//가까운 순서대로 처리하므로 큐를 사용
	pq.push(make_pair(start, 0));
	while (!pq.empty()) {
		int current = pq.top().first; //pq의 최상단 노드에 있는 첫번째값을 현재방문
		//큐의 맨위에는 가장 적은비용을 가지는 노드의 정보가 들어있음
		//짧은것이 먼저 오도록 음수화(-) 시킴
		int distance = -pq.top().second;
		pq.pop(); //queue에서 하나를 꺼냄
		if (mincost[current] < distance) continue; //최단거리가 아닌경우 스킵
		for (int i = 0; i < v[current].size(); i++) {
			//선택된 노드의 인접노드
			int next = v[current][i].first;
			//선택된 노드 거쳐서 인접노드로 가는 비용
			int nextdistance = distance + v[current][i].second;
			//기존의 최소비용보다 더 저렴하다면 교체
			if (nextdistance < mincost[next]) {
				mincost[next] = nextdistance;
				pq.push(make_pair(next, -nextdistance)); //음수화
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