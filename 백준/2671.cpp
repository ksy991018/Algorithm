#include <iostream>
using namespace std;

string s;

int main() {
	cin >> s;
	bool flag = true;

	int cur = 0;
	while (flag && cur<s.size()) {
		if (s[cur] == '0') {
			if (cur + 1 < s.size() && s[cur + 1] == '1') {
				cur += 2;
			}
			else flag = false;
		}
		else {//1로시작
			int zerocnt = 0;
			while (cur< s.size() && s[++cur] == '0') zerocnt++; //100~1 부분검사
			if (zerocnt < 2 || cur==s.size()) flag = false; //0이 2개 미만이거나 1이 모자라는 경우
			else {//100~1까지 통과. 100~1~확인
				cur++; //100~1 다음인덱스 
				while (true) {
					if (cur >= s.size() || s[cur] == '0') break; //범위 벗어나거나 2번쨰 패턴 시작
					if (cur + 2 < s.size() && s.substr(cur, 3) == "100") break; //100이면 1번째 패턴 시작
					else if (cur + 2 < s.size() && s.substr(cur, 3) == "101") { //101이면 0부터 2번쨰패턴 시작
						cur++;
						break;
					}
					cur++; //1로시작하지만 101,100패턴이 아닌경우
				}
			}

		}
	}
	cout << (flag ? "SUBMARINE" : "NOISE") << endl;
}

//#include <iostream>
//#include <regex>
//using namespace std;
//
//int main() {
//	string s;
//	cin >> s;
//	cout << (regex_match(s, regex("(100+1+|01)+")) ? "SUBMARINE": "NOISE") << endl;
//}