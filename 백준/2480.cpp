#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n[3];
	for (int i = 0; i < 3; i++){
		cin >> n[i];
	}

	sort(n, n + 3); //오름차순 정렬
	int num = 0; 
	int cnt;
	int max = 0; //같은 숫자

	for (int i = 0; i < 3; i++){
		cnt = 0;
		for (int j = i; j < 3; j++) { 
			if (n[i] == n[j]) { //수가 같으면 cnt++
				cnt++;
			}
			else { //수가 다르면 즉시종료
				break;
			}
		}
		if (max < cnt) {  //max보다 cnt가 클때
			max = cnt;
			num = n[i]; 
		}
	}

	int result = 0;
	switch (max) {
	case 3:
		result = 10000 + num * 1000;
		break;
	case 2:
		result = 1000 + num * 100;
		break;
	case 1:
		result= 100 * n[2];
		break;
	}
	cout << result << endl;
}