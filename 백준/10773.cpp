#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
int N;

int main() {
	cin >> N;
	int sum=0;
	for (int i = 0; i < N; i++){
		int n;
		cin >> n;
		if (n == 0) {
			s.pop();
		}
		else {
			s.push(n);
		}
	}
	int size = s.size();

	for (int i = 0; i < size; i++) {
		sum += s.top();
		s.pop();
	}
	cout << sum << endl;
}