#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	int card= 0;
	int cnt = 1;
	while (n>=cnt) { //11���� ���ų� ������ 2, 111���� ���ų� ������ 3, ...
		card++;
		cnt += (int)pow(10,card);
	}
	if(n==0){
		card++;
	}
	cout << card << endl;
}