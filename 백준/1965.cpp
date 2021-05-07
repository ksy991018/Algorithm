#include <iostream>
#include <cmath>
using namespace std;

int dp[1000] = { 1,2,1 };

int main() {

	int N;
	cin >> N;
	for (int i = 3; i < N; i++){
		dp[i] = fmin(dp[i - 1], dp[i - 3]) + 1;
	}

	if (dp[N - 1] % 2 == 0)
		cout << "CY" << endl;
	else
		cout << "SK" << endl;
}