#include <iostream>
#include <cmath>
#include <algorithm>
#define INF 1000000
using namespace std;

int dp[10000000] = { INF,0,1,1 };

int calc(int a) {
	int n1=0, n2=0;
	if (a % 2 == 0)
		n1 = a / 2;
	if (a % 3 == 0)
		n2 = a / 3;
	return min({ dp[a - 1], dp[n1], dp[n2] }) + 1;
}

int main() {

	int n;
	cin >> n;
	for (int i = 4; i <=n; i++)
	{
		dp[i] = calc(i);
	}
	cout << dp[n] << endl;
}