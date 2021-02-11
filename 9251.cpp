#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001]; //[�ι�° ���ڿ�][ù��° ���ڿ�]�������� lcs

int main() {
	string a;
	string b;
	cin >> a >> b;

	for (int i = 1; i <= b.size(); i++){//0��° ���� ���� 0����
		for (int j = 1; j <= a.size(); j++) {
			if (a[j - 1] == b[i - 1]) { //���ڰ� ������ lcs 1�� �����ؾ���. ������ ��������?
				dp[i][j] = dp[i - 1][j - 1] + 1; //�δܾ�� ���� ���ڳֱ� �� �������� �� + 1
			}
			else {//�ٸ��� lcs ���� ����. �������� ����ؿ� lcs ����. ������ ��������?
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); //�� �ܾ�� ���繮�� ������ ����� ū�ɷ�
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