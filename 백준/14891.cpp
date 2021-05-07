#include<iostream>
#include <cstdio>
using namespace std;

int first[8],second[8],third[8],fourth[8];
int a,b,K,result;

void turn(int arr[8], int dir) { 
	if (dir == 1) { //시계방향
		int tmp = arr[7];
		for (int i = 7; i >= 1; i--) {
			arr[i] = arr[i - 1];
		}
		arr[0] = tmp;
	}else { //반시계방향
		int tmp = arr[0];
		for (int i = 0; i <= 6; i++) {
			arr[i] = arr[i + 1];
		}
		arr[7] = tmp;
	}
}
void solve(int n, int dir) { //톱니바퀴 번호,방향
	bool onetwo = (first[2] != second[6]); //회전가능여부
	bool twothree = (second[2] != third[6]);
	bool threefour = (third[2] != fourth[6]);
	if (n == 1) {
		turn(first, dir);
		if (onetwo) {
			turn(second, -dir);
			if (twothree){
				turn(third, dir);
				if (threefour) turn(fourth, -dir);
			}		
		}	
	}else if (n == 2) {
		turn(second, dir);
		if (onetwo) turn(first, -dir);
		if (twothree) {
			turn(third, -dir);
			if (threefour) turn(fourth, dir);
		}
	}else if (n == 3) {
		turn(third, dir);
		if (twothree) {
			turn(second, -dir);
			if (onetwo) turn(first, dir);
		}
		if (threefour)  turn(fourth, -dir);
	}else if (n == 4) {
		turn(fourth, dir);
		if (threefour) {
			turn(third, -dir);
			if (twothree) {
				turn(second, dir);
				if (onetwo) turn(first, -dir);
			}
		}
	}
}
int main() {
	for (int i = 0; i < 8; i++)scanf("%1d", &first[i]);
	for (int i = 0; i < 8; i++) scanf("%1d", &second[i]);
	for (int i = 0; i < 8; i++) scanf("%1d", &third[i]);
	for (int i = 0; i < 8; i++) scanf("%1d", &fourth[i]);
	
	cin >> K;
	while(K--){
		cin >> a >> b;
		solve(a, b);
	}
	
	if (first[0]) result += 1;
	if (second[0])result += 2;
	if (third[0]) result += 4;
	if (fourth[0]) result += 8;
	cout << result;
}