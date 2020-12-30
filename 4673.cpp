#include <iostream>
#include <cmath>
using namespace std;


int non_selfcheck(int n) { //d(n)구하는 함수
	int d = n;  //자기 자신 더함
	int tmp = n; //임시저장

	while (tmp > 0) {//각 자리수 더함
		d += tmp % 10; 
		tmp /= 10;
	}
	return d;	
}

int main() {
	int res[10001] = { 0, };
	int non_self;
	for (int i = 1; i < 10000; i++){
		 non_self = non_selfcheck(i); //d(i)
		 if (non_self <= 10000) {
			 res[non_self] = 1; //non-self면 1, 아니면 0
		 }
	}

	for (int i = 1; i <= 10000; i++){
		if (res[i] == 0) {
			cout << i << endl;
		}
	}
}