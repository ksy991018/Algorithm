#include <iostream>
#include <cmath>
using namespace std;

int box[1000];
int dp[1000];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> box[i];
	}

	for (int i = 0; i < n; i++){
		dp[i] = 1;
	}

	for (int i = 1; i < n; i++){
		int max=0;
		for (int j = 0; j < i; j++) {
			if (box[i] > box[j] && dp[j] > max)
				max = dp[j];
		}
		dp[i] = max + 1;
	}

	int result;
	result = 0;
	for (int i = 0; i < n; i++){
		if (dp[i] > result)
			result = dp[i];
	}
	cout << result << endl;
}