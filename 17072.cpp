#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<char> vec;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			int r, g, b,s;
			cin >> r >> g >> b;
			s = 2126 * r + 7152 * g + 722 * b;
			if (s >= 0 && s < 510000) {
				vec.push_back('#');
			}
			else if (s < 1020000) {
				vec.push_back('o');
			}
			else if (s < 1530000) {
				vec.push_back('+');
			}
			else if (s < 2040000) {
				vec.push_back('-');
			}
			else {
				vec.push_back('.');
			}

		}
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << vec[k++];
		}
		cout << endl;
	}
}