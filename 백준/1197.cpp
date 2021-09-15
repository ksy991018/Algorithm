#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;
int A, B, C;

int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	else return 0;
}

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator<(Edge& edge) {
		return this->distance < edge.distance;
	}
};

int main() {
	cin >> V >> E;
	vector<Edge> v;
	int parent[10000];

	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		v.push_back({ A,B,C });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < V; i++) {
		parent[i] = i;
	}
	int sum = 0;

	for (int i = 0; i < v.size(); i++){
		if (!findParent(parent, v[i].node[0]-1, v[i].node[1]-1)) {
			sum += v[i].distance;
			unionParent(parent, v[i].node[0]-1, v[i].node[1]-1);
		}
	}
	cout << sum << endl;
}