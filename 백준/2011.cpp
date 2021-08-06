#include <iostream>
#include <string>
#define mod 1000000
using namespace std;

int main() {
    string s; 
    cin >> s;
    int size = s.size();

    if (s[0] == '0') {
        cout << 0; return 0;
    }

    int dp[5001] = { 1,1 }; // dp의 0,1번째 값은 1
    for (int i = 2; i <= size; i++) {
        int cur = s[i-1] - '0';
        int prev = s[i - 2] - '0';
        int tmp = prev * 10 + cur;

        //뒤에 새로운 숫자가 들어왔을때
        if (cur!=0) dp[i] = dp[i - 1] % mod; //숫자 한개로 암호 만드는 경우의 수. 즉 dp[i-1] 

        if (10 <= tmp && 26 >= tmp) {// 숫자 두개로 암호 만드는 경우의 수 dp[i-1]
            dp[i] = (dp[i] + dp[i - 2]) % mod;
        }
    }
    cout << dp[size];
}

