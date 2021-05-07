#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt;
int visit[20];

void dfs(vector<int> numbers, int sum,int cur,int target) {
	if (sum == target && cur ==numbers.size()) {
		cnt++;
		return;
	}
	if (cur==numbers.size()) return;
	
	dfs(numbers, sum + numbers[cur], cur + 1, target);
	dfs(numbers, sum - numbers[cur], cur + 1, target);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	dfs(numbers, 0,0,target);
	answer = cnt;
	return answer;
}

int main() {
	vector<int> v = { 1,1,1,1,1 };
	cout << solution(v, 3);
}