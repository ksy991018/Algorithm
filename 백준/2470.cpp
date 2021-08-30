#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,n,L,R;
int result= 2000000001;
vector<int> v;
int finalL, finalR;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());

	L = 0; R = N - 1;
	int tmpSum;
	while (L < R) {
		tmpSum = v[L] + v[R];
		if (result > abs(tmpSum)) {
			result = abs(tmpSum);
			finalL = v[L];
			finalR = v[R];
		}
		if (tmpSum > 0)R--;
		else L++;
	}
	cout << finalL << " " << finalR << endl;
}