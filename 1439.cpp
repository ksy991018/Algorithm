#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;

	int cnt1 = 0;
	for (int i = 0; i < s.length(); i++){
		if (s[i] == '1') {
			if (s[i + 1] == '0' || i==s.length()-1) { //1¿¡¼­ 0¹Ù²ð¶§
				cnt1++;
			}		
		}
	}
	int cnt2 = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
			if (s[i + 1] == '1' || i==s.length()-1) { //0¿¡¼­ 1¹Ù²ð¶§
				cnt2++;
			}
		}
	}
	cout << min(cnt1, cnt2) << endl;
}