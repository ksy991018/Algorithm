#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	else return parent[x] = getParent(parent, parent[x]);
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
	if (a == b)return 1;
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
	bool operator<(Edge& e) {
		return this->distance < e.distance;
	}
};

int main() {
	cin >> N >> M;
	int a, b, distance;
	vector<Edge> v;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> distance;
		v.push_back(Edge(a, b, distance));
	}
	sort(v.begin(), v.end());
	int parent[100001];
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	int sum = 0;
	int separate = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!findParent(parent,v[i].node[0], v[i].node[1])) {
			unionParent(parent, v[i].node[0], v[i].node[1]);
			sum += v[i].distance;
			separate = max(separate, v[i].distance);
		}
	}
	cout << sum-separate << endl;
}