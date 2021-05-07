#include <iostream>
using namespace std;

int main() {
	char m[2];
	char t[2];
	bool win = false;
	bool lose = false;

	for (int i = 0; i < 2; i++){
		cin >> m[i];
	}
	for (int i = 0; i < 2; i++) {
		cin >> t[i];
	}

	if (m[0] == m[1]) {
		if (m[0] == 'R') {
			if (t[0] == 'P' || t[1] == 'P') {
				lose = true;
			}
			else if (t[0] == 'S' && t[1] == 'S') {
				win = true;
			}
		}
		if (m[0] == 'P') {
			if (t[0] == 'S' || t[1] == 'S') {
				lose = true;
			}
			else if (t[0] == 'R' && t[1] == 'R') {
				win = true;
			}
		}
		if (m[0] == 'S') {
			if (t[0] == 'R' || t[1] == 'R') {
				lose = true;
			}
			else if (t[0] == 'P' && t[1] == 'P') {
				win = true;
			}
		}
	}
	else if (t[0] == t[1]) {
		if (t[0] == 'R') {
			if (m[0] == 'P' || m[1] == 'P') {
				win = true;
			}
			else if (m[0] == 'S' && m[1] == 'S') {
				lose= true;
			}
		}
		if (t[0] == 'P') {
			if (m[0] == 'S' || m[1] == 'S') {
				win = true;
			}
			else if (m[0] == 'R' && m[1] == 'R') {
				lose = true;
			}
		}
		if (t[0] == 'S') {
			if (m[0] == 'R' || m[1] == 'R') {
				win = true;
			}
			else if (m[0] == 'P' && m[1] == 'P') {
				lose = true;
			}
		}
	}
	else {
		for (int i = 0; i < 2; i++) {
			if (m[i] == 'R') {
				if (t[0] == 'S' || t[1] == 'S') {
					win = true;
				}
				if (t[0] == 'P' || t[1] == 'P') {
					lose = true;
				}
			}
			else if (m[i] == 'S') {
				if (t[0] == 'P' || t[1] == 'P') {
					win = true;
				}
				if (t[0] == 'R' || t[1] == 'R') {
					lose = true;
				}
			}
			else if (m[i] == 'P') {
				if (t[0] == 'R' || t[1] == 'R') {
					win = true;
				}
				if (t[0] == 'S' || t[1] == 'S') {
					lose = true;
				}
			}
		}
	}

	if (win == lose) {
		cout << "?" << endl;
	}
	else if (win) {
		cout << "MS" << endl;
	}
	else if (lose) {
		cout << "TK" << endl;
	}
}