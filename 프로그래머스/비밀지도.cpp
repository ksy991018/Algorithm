#include <string>
#include <vector>
#include <iostream>

using namespace std;

//vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
//	vector<string> answer;
//	for (int i = 0; i < n; i++){
//		string tmp = "";
//		for (int j = n - 1; j >= 0; j--) {
//			if (arr1[i] & (1 << j) | arr2[i] & (1 << j)) { //arr1,arr2의 i번째 비트중 하나라도 1이라면 
//				tmp += "#";
//			}
//			else {
//				tmp += " ";
//			}
//		}
//		answer.push_back(tmp);
//	}
//
//	return answer;
//}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i < n; i++) {
		arr1[i] = arr1[i] | arr2[i]; //각비트를 or연산

		string ans = "";
		for (int j = 0; j < n; j++) {//2진수로 
			if (arr1[i] % 2 == 0) ans = " " + ans;
			else ans = "#" + ans;
			arr1[i] = arr1[i] >> 1;
		}
		answer.push_back(ans);
	}
	return answer;
}
int main() {
	vector<string> result = solution(5, { 9, 20, 28, 18, 11 }, { 30, 1, 21, 17, 28 });
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << endl;
	}
}