#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n[3];
	for (int i = 0; i < 3; i++){
		cin >> n[i];
	}

	sort(n, n + 3); //�������� ����
	int num = 0; 
	int cnt;
	int max = 0; //���� ����

	for (int i = 0; i < 3; i++){
		cnt = 0;
		for (int j = i; j < 3; j++) { 
			if (n[i] == n[j]) { //���� ������ cnt++
				cnt++;
			}
			else { //���� �ٸ��� �������
				break;
			}
		}
		if (max < cnt) {  //max���� cnt�� Ŭ��
			max = cnt;
			num = n[i]; 
		}
	}

	int result = 0;
	switch (max) {
	case 3:
		result = 10000 + num * 1000;
		break;
	case 2:
		result = 1000 + num * 100;
		break;
	case 1:
		result= 100 * n[2];
		break;
	}
	cout << result << endl;
}