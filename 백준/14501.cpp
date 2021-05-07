#include <iostream>
#include <algorithm>
using namespace std;

int N;
int T[16]; //���ҿ���
int P[16]; //�ݾ�
int result[16];
int greatest; //������� �ִ����

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> T[i] >> P[i];
	}

	if (T[N] == 1) result[N] = P[N]; //��������

	int day = 0; //���� ���Ҵ��� 

	for (int i = N; i >= 1; i--){ //�ڿ�������
		day++;
		if (T[i] > day) result[i] = greatest; //�ҿ���>�����ϼ�-> ������� �ִ����
		else result[i] = max(result[i + T[i]]+P[i], result[i + 1]); //�����Ҷ� ���Ҷ�
		
		greatest = max(greatest, result[i]); //�ִ���� ����
	}

	cout << greatest;
}