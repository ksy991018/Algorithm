#include <iostream>
#include <cmath>
using namespace std;


int non_selfcheck(int n) { //d(n)���ϴ� �Լ�
	int d = n;  //�ڱ� �ڽ� ����
	int tmp = n; //�ӽ�����

	while (tmp > 0) {//�� �ڸ��� ����
		d += tmp % 10; 
		tmp /= 10;
	}
	return d;	
}

int main() {
	int res[10001] = { 0, };
	int non_self;
	for (int i = 1; i < 10000; i++){
		 non_self = non_selfcheck(i); //d(i)
		 if (non_self <= 10000) {
			 res[non_self] = 1; //non-self�� 1, �ƴϸ� 0
		 }
	}

	for (int i = 1; i <= 10000; i++){
		if (res[i] == 0) {
			cout << i << endl;
		}
	}
}