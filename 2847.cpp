#include <iostream>
using namespace std;

int N;
int arr[101];
int cnt;

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++){
		cin >> arr[i];
	}
	
	for (int i = N-1; i>0; i--){//�ڿ������� ���
		if (arr[i] >= arr[i + 1]) {//�� ���� �������� ũ�� �� ��������-1�� ������
			cnt += arr[i] - arr[i + 1] + 1;
			arr[i] = arr[i + 1] - 1;
		}
	}
	cout << cnt;
}