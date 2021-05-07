#include <iostream>
#include <vector>
using namespace std;

int N, S; //���� ���� , �κм��� ��
int result; //�κм��� ����
int arr[20];

void solve(int cnt, int sum, int flag) { //flag: ���� ������ ��ȭ ����
	if (cnt == N+1) return; 

	if (sum == S && flag) result++; //���� ������ �Ȱ����� �ߺ� ���� ���� 

	solve(cnt + 1, sum + arr[cnt],1);
	solve(cnt + 1, sum,0);
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}

	solve(0, 0, 0);
	cout << result;
}