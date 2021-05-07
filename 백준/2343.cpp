#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100000];
//이분탐색 대상 : 블루레이 크기

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	int minSize = 0; //왼쪽끝값
	int maxSize = 0; //오른쪽 끝값

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		arr[i] = n;
		maxSize += n; //입력한수 다 더한값
		minSize = max(minSize, n); //입력한 수중 가장 큰값
	}

	while (minSize <= maxSize) {
		int curSize = (maxSize + minSize) / 2; //현재 블루레이 크기
		int tmp = 0;
		int use = 0;

		for (int i = 0; i < N; i++) {
			if (tmp + arr[i] > curSize) {
				use++;
				tmp = 0;
			}
			tmp += arr[i];
		}
		if (use > M - 1) minSize = curSize + 1; //블루레이 개수 초과하면 반등분한거에서 오른쪽
		else maxSize = curSize - 1;  //반등분한거에서 왼쪽 (구하는것이 최소기때문)
	}

	cout << minSize;
}