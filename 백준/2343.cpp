#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100000];
//�̺�Ž�� ��� : ��緹�� ũ��

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	int minSize = 0; //���ʳ���
	int maxSize = 0; //������ ����

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		arr[i] = n;
		maxSize += n; //�Է��Ѽ� �� ���Ѱ�
		minSize = max(minSize, n); //�Է��� ���� ���� ū��
	}

	while (minSize <= maxSize) {
		int curSize = (maxSize + minSize) / 2; //���� ��緹�� ũ��
		int tmp = 0;
		int use = 0;

		for (int i = 0; i < N; i++) {
			if (tmp + arr[i] > curSize) {
				use++;
				tmp = 0;
			}
			tmp += arr[i];
		}
		if (use > M - 1) minSize = curSize + 1; //��緹�� ���� �ʰ��ϸ� �ݵ���Ѱſ��� ������
		else maxSize = curSize - 1;  //�ݵ���Ѱſ��� ���� (���ϴ°��� �ּұ⶧��)
	}

	cout << minSize;
}