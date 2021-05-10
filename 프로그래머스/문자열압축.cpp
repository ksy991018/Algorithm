#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool check(int n, int size) {
	int tmp = 1;
	while (tmp <= size) { //10�� �ŵ����� ��������
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
			if ((j + i) > s.length()) {//������ 
				cnt += (s.length() - j);
			}
			else if (tmp == s.substr(j, i)) {
				tmpcnt++;
				if (tmpcnt==2 || check(tmpcnt,s.length())) cnt++;  //�ڸ��� �ٲ𶧸��� 			
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