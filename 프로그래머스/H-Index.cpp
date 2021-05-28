#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end(), greater<int>());
	for (int i = 0; i < citations.size(); i++) {
		if (citations[i] <= answer) break;  //answer보다 같거나 작으면 answer개 이상 answer번 보장됨. 
		answer++;
	}
	return answer;
}

int main() {
	cout << solution({ 7,6,4,3,1,0 });
}