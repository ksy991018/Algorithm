#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b)
		return 1;
	else
		return 0;
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
	bool operator <(Edge& edge) {
		return this->distance < edge.distance;
	}
};

int main() {
	int n, m; //정점 간선
	cin >> n >> m;

	int a, b, distance;
	vector<Edge> v;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> distance;
		v.push_back(Edge(a, b, distance));
	}

	sort(v.begin(), v.end());

	int parent[10000];
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	vector<Edge> c;
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].distance;
			c.push_back(Edge(a, b, distance));
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}
	cout << sum;
}