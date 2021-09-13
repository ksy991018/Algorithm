#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,n;
int arr[1000];

//K-INDEX : K보다 같거나 큰숫자를 K개이상 선택가능 & K보다 같거나 작은숫자를 N-K이상 선택가능
int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	for (int i = N; i >=0; i--){ //최대 N개까지 선택하므로 N부터 탐색
		int cnt = 0;
		for (int j = 0; j < N; j++) { //I-INDEX 가정
			if (arr[j] >= i) cnt++;
		}
		if (cnt >= i) { //I보다 같거나 큰숫자가 I개 이상 -> i보다 작은 숫자는 N-i개로 두번쨰 조건도 자동 만족  
			cout << i << endl;
			break;
		}
	}
}