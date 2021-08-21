#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string dp[251] = { "1","1","3" };
int largest=2;

//점화식 : dp[i] = dp[i-1] + 2*dp[i-2] = dp[i-1] + dp[i-2] + dp[i-2]

//문자열을 통한 큰 수 덧셈
void string_add(int from, int to) {
	for (int i = from; i <= to; i++) {
		string a = dp[i - 1], b = dp[i - 2], c = dp[i - 2];
		int sum = 0;
		string result; //숫자들을 뒤에서부터 더해서 저장 
		while (!a.empty() || !b.empty() || !c.empty() || sum) { //모두 빈문자열이거나 올림수가 더이상 없는경우
			if (a != "") {
				sum += a.back() - '0'; //string to int
				a.pop_back();
			}
			if (b != "") {
				sum += b.back() - '0';
				b.pop_back();
			}
			if (c != "") {
				sum += c.back() - '0';
				c.pop_back();
			}
			result.push_back(sum % 10 + '0'); //다 더했을때 마지막자릿수
			sum /= 10; //올림수
		}
		reverse(result.begin(), result.end()); //거꾸로 계산했으므로
		dp[i] = result;
	}
}

int main() {
	while (cin >> N) {
		if (largest < N) {
			string_add(largest, N);
			largest = N;
		}
		cout << dp[N]<<endl;
	}
}