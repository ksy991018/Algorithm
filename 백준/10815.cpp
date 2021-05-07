#include <iostream>
#include <algorithm>
using namespace std;
int num[500000];
int check[500000];
int n, m, k;

int kcheck(int start, int end, int k) {
	int mid = (start + end) / 2;

	if (start > end)
		return 0;
	if (num[mid] == k)
		return 1;
	if (num[mid] < k)
		return kcheck(mid + 1, end, k);
	if (num[mid] > k)
		return kcheck(start, mid - 1, k);
}



int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	sort(num, num + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> k;
		check[i] = kcheck(0, n - 1, k);
	}

	for (int i = 0; i < m; i++) {
		cout << check[i] << " ";
	}

}

