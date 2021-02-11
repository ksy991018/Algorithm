#include <iostream>
#include <queue>
using namespace std;

int N; //������ ����
priority_queue<int,vector<int>,greater<int>> pq; //�������� ����
int total; //�ǹ� : total���� ������������

//���̵�� : �������� ���� �� i-1��°���� �������� ù��° �ߺ��� i-1������ �߸� �̿��� ����� �ִ� �ִ� ����
//����, i��° �� ���԰� (i-1��°������ ������+1)���� ũ�ٸ� (i-1��°������ ������+1)�� ������ִ� ����� ����.

//total ���� ������(���� ������ total+value[i])
//total(i-1���� ������) = 5, value(i��°��) = 6�̸� (6+1,6+2,6+3,6+4,6+5=11) total=11���� ���������.

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		pq.push(n);
	}

	while (N--) {
		int value = pq.top();
		pq.pop();
		if (value > total + 1) break; //total+1���� ���� ������ �߰� ũ�� total+1�� ����ִ� ����� ������.(total������ ��������)
		else total += value; //������
	}
	cout << total + 1;
}