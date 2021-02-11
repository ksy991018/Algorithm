#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001]; //[두번째 문자열][첫번째 문자열]비교했을때 lcs

int main() {
	string a;
	string b;
	cin >> a >> b;

	for (int i = 1; i <= b.size(); i++){//0번째 열과 줄은 0으로
		for (int j = 1; j <= a.size(); j++) {
			if (a[j - 1] == b[i - 1]) { //문자가 같으면 lcs 1개 증가해야함. 무엇을 기준으로?
				dp[i][j] = dp[i - 1][j - 1] + 1; //두단어에서 현재 문자넣기 전 비교했을때 값 + 1
			}
			else {//다르면 lcs 증가 안함. 그전까지 계산해온 lcs 유지. 무엇을 기준으로?
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); //각 단어에서 현재문자 뺏을때 경우중 큰걸로
			}
		}
	}

	for (int i = 0; i <=b.size(); i++){
		for (int j = 0; j <= a.size(); j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	cout << dp[b.size()][a.size()];
}