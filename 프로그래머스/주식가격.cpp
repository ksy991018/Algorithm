#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	stack<int> s;
	int size = prices.size(); // ��� size�� ����ϴ� �ͺ��� ��������� �����ϸ� ��ü �Լ� ó�� �ð� ����

	for (int i = 0; i < size; ++i) {
		cout << i << "��°" << endl;
		while (!s.empty() && prices[s.top()] > prices[i]) { // ������ �پ����ٸ�
			cout << s.top() <<  ": ";
			answer[s.top()] = i - s.top(); // ���� �ð� - ��� �ð�
			cout << answer[s.top()] << endl;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		answer[s.top()] = size - 1 - s.top(); // ���� �ð� - ��� �ð�
		s.pop();
	}

	return answer;
}


int main() {
	vector<int> v = solution({ 1,2,3,2,1 });
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}