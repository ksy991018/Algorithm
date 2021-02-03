#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

int N;
priority_queue<int,vector<int>,greater<int>> positive; //���
priority_queue<int,vector<int>,greater<int>> negative; //����(�켱����{)

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		int n;
		cin >> n;
		if (n > 0) {
			positive.push(n);
		}
		else if (n < 0) {
			negative.push(abs(n)); //����
		}
		else {//���������� ���
			if (positive.empty() && negative.empty()) {
				cout << 0 << "\n";
			}
			else if (positive.empty()) {
				cout << -1*negative.top() << "\n"; //-1 ���ϱ�
				negative.pop();
			}
			else if (negative.empty()) {
				cout << positive.top() << "\n";
				positive.pop();
			}
			else if (positive.top() < negative.top()) { //���ų� pos�� �� ������ �켱������ neg
				cout << positive.top() << "\n";
				positive.pop();
			}
			else {
				cout << -1*negative.top() << "\n";
				negative.pop();
			}
		}
	}
}