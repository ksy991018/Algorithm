#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int tmp = n;
	while (tmp >= 1) {
		if (tmp == 1) {
			cout << tmp << " bottle of beer on the wall, " << tmp << " bottle of beer." << endl;
		}
		else {
			cout << tmp << " bottles of beer on the wall, " << tmp << " bottles of beer." << endl;
		}
		
		if (tmp == 2) {
			cout << "Take one down and pass it around, " << tmp - 1 << " bottle of beer on the wall." << endl;
		}else if (tmp == 1) {
			cout << "Take one down and pass it around, no more bottles of beer on the wall." << endl;
		}
		else {
			cout << "Take one down and pass it around, " << tmp - 1 << " bottles of beer on the wall." << endl;
		}	
		cout << endl;
		tmp--;
	}
	cout << "No more bottles of beer on the wall, no more bottles of beer." << endl;
	if (n == 1) {
		cout << "Go to the store and buy some more, " << n << " bottle of beer on the wall." << endl;
	}
	else {
		cout << "Go to the store and buy some more, " << n << " bottles of beer on the wall." << endl;
	}
	
}