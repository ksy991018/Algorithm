#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end(), greater<int>());
	for (int i = 0; i < citations.size(); i++) {
		if (citations[i] <= answer) break;  //answer���� ���ų� ������ answer�� �̻� answer�� �����. 
		answer++;
	}
	return answer;
}

int main() {
	cout << solution({ 7,6,4,3,1,0 });
}