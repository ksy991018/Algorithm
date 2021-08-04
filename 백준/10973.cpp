#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,n;
vector<int> v;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> n;
		v.push_back(n);
	}
	
	if (prev_permutation(v.begin(), v.end())) { //이전 순열 구하는 함수. 존재하면 True
		for (int i = 0; i < N; i++) {
			cout << v[i] << " ";
		}
	}
	else {
		cout << -1 << endl;
	}
}