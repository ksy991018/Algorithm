#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[10000];
int result;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	result = max(arr[N - 1] * arr[N - 2], arr[N - 1] * arr[N - 2] * arr[N - 3]);
	if (arr[0] * arr[1] > 0) { //둘다 음수
		result = max({ result,arr[0] * arr[1],arr[0] * arr[1] * arr[N - 1] });
	}
	cout << result << endl;
}