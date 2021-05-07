#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int> pq; //최대힙. 디폴트가 내림차순
//priority_queue<int,vector<int>,greater<int>> pq는 오름차순으로 최소힙
//가장 큰값을 출력해야 하니까 내림차순으로 정렬 
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
	return 0;
}