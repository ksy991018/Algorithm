#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	int card= 0;
	int cnt = 1;
	while (n>=cnt) { //11보다 같거나 작으면 2, 111보다 같거나 작으면 3, ...
		card++;
		cnt += (int)pow(10,card);
	}
	if(n==0){
		card++;
	}
	cout << card << endl;
}