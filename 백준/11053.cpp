#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1001];
int dp[1001];//����� �����ϴ� �κм��� ����
int best=1;//0���� �ϸ� N�� 1�ϰ�� Ʋ��

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	dp[0] = 1;
	for (int i = 1; i < N; i++){
		int tmp=0;
		for (int j = 0; j < i; j++){
			if (arr[j] < arr[i]) { //����� ���� ���� ������ dp�� ����ū�� +1
				tmp = max(dp[j], tmp);
			}
		}
		dp[i] = tmp + 1;
		if (best < dp[i]) best = dp[i];		//dp���� ����ū��	
	}
	cout << best;
}