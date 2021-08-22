#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, result;
vector<int> v(6);
int one = 5000, two = 5000, three = 5000;
int largest,sum;

int main() {
	cin >> N;

	for (int i = 0; i < 6; i++) {
		cin >> v[i];
		sum += v[i];
		largest = max(largest, v[i]);
	}

	for (int i = 0; i < 6; i++){
		one = min(one, v[i]);
		for (int j = i + 1; j < 6; j++) {
			if (i + j == 5) continue;
			two = min(v[i] + v[j], two);
			for (int k = j + 1; k < 6; k++) {
				if (i + k == 5 || j + k == 5) continue;
				three = min(three, v[i] + v[j] + v[k]);
			}
		}
	}
	if (N == 1) result = sum - largest;
	else result = (4 * three) + ((8*N-12)*two) + (5 * N - 6) * (N - 2) * one;
	cout << result << endl;
}