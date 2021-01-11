#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#define MAX 32001
using namespace std;

//위상정렬: 순서가 정해져있는 작업을 차례로 수행해야할때 순서 결정해주는 알고리즘
//규칙을 지키면서 가능하면 낮은 숫자부터 출력해야하기 때문에 우선순위 큐 사용.
priority_queue<int, vector<int>, greater<int>> pq; //오름차순 : 작은숫자부터 출력
int N, n;
int inDegree[MAX];
vector<int> v[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> n;
	for (int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b); //그래프 그리기 
		inDegree[b]++; //위상 추가
	}

	for (int i = 1; i <=N ; i++){
		if (inDegree[i] == 0) { //진입차수 0인 노드를 큐에 삽입
			pq.push(i);
		}
	}

	while(!pq.empty()){
		int x = pq.top();
		pq.pop();
		cout << x << " ";
		for (int i = 0; i < v[x].size(); i++){ //pop한 노드랑 연결된 노드들의 위상을 줄임.
			int tmp = v[x][i];
			if (--inDegree[tmp] == 0) { //새롭게 진입차수 0인 노드 큐 삽입
				pq.push(tmp);
			}
		}
	}
}