#include <iostream>
#include <algorithm>
using namespace std;

int seq[10000];
int N;
int result = 0;
int index = 0;

int main() {
	int minus = 0, plus = 0, zero=0;
	cin >> N;
	for (int i = 0; i < N; i++){
		int n;
		cin >> n;
		seq[i] = n;
		if (n > 0) {
			plus++;
		}
		else if(n<0){
			minus++;
		}
		else {
			zero++;
		}
	}

	sort(seq, seq + N); 

	for (int i = 0; i < minus / 2; i++) {
		result += seq[index] * seq[index + 1];
		index += 2;
	}
	if (minus % 2 != 0) {
		if (zero == 0) {
			result += seq[index];
			index ++;
		}
		else {
			index += 1+zero;
		}
	}
	else {
		if (zero > 0) {
			index += zero;
		}
	} 

	int tmp = N - 1;
	for (int i = 0; i <plus/2; i++) {
		if (seq[tmp] <= 2 || seq[tmp-1]==1) {
			result += seq[tmp] + seq[tmp - 1];
		}else {
			result += seq[tmp] * seq[tmp - 1];
		}
		tmp -= 2;
	}
	if (plus % 2 != 0) {
		result += seq[index];
	}

	cout << result << endl;

}