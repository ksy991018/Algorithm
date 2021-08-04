#include <iostream>
#include <queue>
using namespace std;

int N,M,n;
long long int a, b,sum;
priority_queue<long long int,vector<long long int>,greater<long long int>> pq;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> n;
		pq.push(n);
	}
	
	while (M--) {
		a = pq.top(); pq.pop();
		b = pq.top(); pq.pop();
		pq.push(a + b); pq.push(a + b);
	}
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum << endl;
}