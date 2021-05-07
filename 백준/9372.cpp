#include <iostream>
using namespace std;

int T,N, M; //나라,비행기

int main() {
	cin >> T;
	
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < M; i++){
			int a, b;
			cin >> a >> b;
		}
		cout << N - 1 << "\n"; //최소 비행기개수 == 간선의 개수
	}
}