#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string dp[251] = { "1","1","3" };
int largest=2;

//��ȭ�� : dp[i] = dp[i-1] + 2*dp[i-2] = dp[i-1] + dp[i-2] + dp[i-2]

//���ڿ��� ���� ū �� ����
void string_add(int from, int to) {
	for (int i = from; i <= to; i++) {
		string a = dp[i - 1], b = dp[i - 2], c = dp[i - 2];
		int sum = 0;
		string result; //���ڵ��� �ڿ������� ���ؼ� ���� 
		while (!a.empty() || !b.empty() || !c.empty() || sum) { //��� ���ڿ��̰ų� �ø����� ���̻� ���°��
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
			result.push_back(sum % 10 + '0'); //�� �������� �������ڸ���
			sum /= 10; //�ø���
		}
		reverse(result.begin(), result.end()); //�Ųٷ� ��������Ƿ�
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