#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int,int>> t;
vector<int>v;
int dp[501];
int result;


int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		t.push_back({ a,b });
	}
	sort(t.begin(), t.end());
	for (int i = 0; i < t.size(); i++){
		v.push_back(t[i].second);
	}

	for (int i = 0; i < v.size(); i++){ //가장긴 증가하는 부분수열 
		int tmp = 0;
		for (int j = 0; j < i; j++){
			if (v[j] < v[i]) tmp = max(tmp, dp[j]);
		}
		dp[i] = tmp + 1;
		result = max(result, dp[i]);
	}

	cout << N-result;
}