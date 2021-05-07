#include <iostream>
#include <algorithm>
using namespace std;

int N;
int T[16]; //상담소요일
int P[16]; //금액
int result[16];
int greatest; //현재까지 최대수익

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> T[i] >> P[i];
	}

	if (T[N] == 1) result[N] = P[N]; //마지막날

	int day = 0; //몇일 남았는지 

	for (int i = N; i >= 1; i--){ //뒤에서부터
		day++;
		if (T[i] > day) result[i] = greatest; //소요일>남은일수-> 현재까지 최대수익
		else result[i] = max(result[i + T[i]]+P[i], result[i + 1]); //선택할때 안할때
		
		greatest = max(greatest, result[i]); //최대수익 갱신
	}

	cout << greatest;
}