#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int> pq; //�ִ���. ����Ʈ�� ��������
//priority_queue<int,vector<int>,greater<int>> pq�� ������������ �ּ���
//���� ū���� ����ؾ� �ϴϱ� ������������ ���� 
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++){
		int n;
		cin >> n;
		if (n == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n"; 
				pq.pop();
			}
		}
		else {
			pq.push(n);
		}
	}
	return 0;
}