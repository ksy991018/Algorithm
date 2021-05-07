#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

struct meeting {
	int begin;
	int end;
};

bool compare(meeting a, meeting b) {
	if (a.end == b.end) return a.begin < b.begin;
	else return a.end < b.end;
}

int main() {
	cin >> N;
	vector<meeting> v(N);
	for (int i = 0; i < N; i++){
		cin >> v[i].begin >> v[i].end;
	}
	sort(v.begin(), v.end(), compare);

	int result = 0;
	int possible = 0;
	for (int i = 0; i < v.size(); i++){
		if (possible <= v[i].begin) {
			possible = v[i].end;
			result++;
		}
	}
	cout << result;
}