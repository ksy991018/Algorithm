#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 1000001;
int stair[MAX];
int DP[MAX];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stair[i];
	}
	DP[1] = stair[1];
	DP[2] = stair[1] + stair[2];
	DP[3] = fmax(DP[1] + stair[3], stair[2] + stair[3]);
	for (int i = 4; i <= N; i++) {
		DP[i] = fmax(DP[i - 2] + stair[i], DP[i - 3] + stair[i - 1] + stair[i]);
	}
	cout << DP[N];
	return 0;
}
//
//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int value[300];
//
//int maxvalue(int stair) {
//	int current, case1=0, case2=0;
//	int a = 0;
//
//	for (int i = stair-1; i >=0; i--){
//		(fmax(case1, case2) == case1 && i<stair-1? a++:a=0);
//		if (a == 2) {
//			current = value[i] + case2;
//			a = 0;
//		}
//		else
//			current = value[i] + fmax(case1, case2);
//		case2 = case1;
//		case1 = current;
//		cout << endl;
//		cout << current << " " <<  case1 << " " << case2 << endl;
//	} 
//	
//	return fmax(case1, case2);
//}
//
//int main() {
//	int stair;
//	cin >> stair;
//
//	for (int i = 0; i < stair; i++){
//		cin >> value[i];
//	}
//
//	cout << maxvalue(stair) << endl;
//}
//
