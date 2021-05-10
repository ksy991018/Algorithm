#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool check(int n, int size) {
	int tmp = 1;
	while (tmp <= size) { //10의 거듭제곱 형태인지
		tmp *= 10;
		if (tmp == n) return true;
	}
	return false;
}

int solution(string s) {
	int answer = 100000;
	for (int i = 1; i <= s.length(); i++){
		int cnt = 0;
		string tmp = "";
		bool flag = true;
		int tmpcnt = 0;
		for (int j = 0; j < s.length(); j+=i){
			if ((j + i) > s.length()) {//마지막 
				cnt += (s.length() - j);
			}
			else if (tmp == s.substr(j, i)) {
				tmpcnt++;
				if (tmpcnt==2 || check(tmpcnt,s.length())) cnt++;  //자리수 바뀔때마다 			
			}
			else {
				tmpcnt = 1;
				cnt +=i;
				tmp = s.substr(j, i);
				flag = true;
			}
		}
		answer = min(answer, cnt);
	}
	return answer;
}

int main() {
	cout << solution("zxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
}