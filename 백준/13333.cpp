#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,n;
int arr[1000];

//K-INDEX : K���� ���ų� ū���ڸ� K���̻� ���ð��� & K���� ���ų� �������ڸ� N-K�̻� ���ð���
int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	for (int i = N; i >=0; i--){ //�ִ� N������ �����ϹǷ� N���� Ž��
		int cnt = 0;
		for (int j = 0; j < N; j++) { //I-INDEX ����
			if (arr[j] >= i) cnt++;
		}
		if (cnt >= i) { //I���� ���ų� ū���ڰ� I�� �̻� -> i���� ���� ���ڴ� N-i���� �ι��� ���ǵ� �ڵ� ����  
			cout << i << endl;
			break;
		}
	}
}