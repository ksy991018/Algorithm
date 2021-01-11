#include <iostream>
#include <queue>

using namespace std;
//11279와 유사

priority_queue<int, vector<int>, greater<int>> pq; //가장 작은 값 출력해야하므로 오름차순 
int N;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++){
		int n;
		cin >> n;
		if (n == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(n);
		}
	}
}