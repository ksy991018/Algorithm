#include <iostream>
using namespace std;

int T,H,W,N;
int hotel[100][100];
int X, Y;

int main() {
	cin >> T;
	while (T--) {
		cin >> H >> W >> N;
		Y = (N % H==0? H : N % H);
		X = (N % H==0? N/H : N / H + 1);
		cout << 100 * Y + X << endl;
	}
}