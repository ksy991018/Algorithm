#include <iostream>
#include <stack>
using namespace std;

string s;
stack<char> c;
int flag = 0;
int result;
int out;
int tmp = 1;

//ºÐ¹è¹ýÄ¢ . ¿©´Â °ýÈ£ÀÏ¶§ tmp°ª ¿Ã¸² & °ýÈ£ ¹Ù·Î ´ÝÈú¶§¸¸ result¿¡ ´õÇØÁÜ.
// (()[[]]) = 2*(2+3*(3)) = 2*2 + 2*3*3   

int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') { //¿©´Â °ýÈ£ÀÏ¶§ tmp°öÇØÁÜ
			tmp *= 2;
			c.push('(');
		}
		else if (s[i] == '[') {
			tmp *= 3;
			c.push('[');
		}
		else if (c.empty() || (c.top() == '(' && s[i] != ')') || (c.top() == '[' && s[i] != ']')) { //ºñ¾îÀÖ°Å³ª °ýÈ£½Ö ¾È¸ÂÀ»¶§
			flag = 1;
			break;
		}
		else if (s[i] == ']') {
			if (s[i - 1] == '[') { //¹Ù·Î ´ÝÈ÷¸é
				result += tmp;
			}
			c.pop();
			tmp /= 3; //°ýÈ£ ÇÏ³ª ºüÁ³±â ¶§¹®
		}
		else if (s[i] == ')') {
			if (s[i - 1] == '(') { //¹Ù·Î ´ÝÈ÷¸é 
				result += tmp;
			}
			c.pop();
			tmp /= 2;
		}

	}
	if (flag || !c.empty()) cout << 0;
	else cout << result;
}