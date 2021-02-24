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
	
	for (int i = N-1; i>0; i--){//뒤에서부터 계산
		if (arr[i] >= arr[i + 1]) {//뒤 레벨 점수보다 크면 뒤 레벨점수-1로 내리기
			cnt += arr[i] - arr[i + 1] + 1;
			arr[i] = arr[i + 1] - 1;
		}
	}
	cout << cnt;
}