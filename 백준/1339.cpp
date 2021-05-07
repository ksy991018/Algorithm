#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
vector<string> v;
int alpha[26] = { 0, };
int result = 0;

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	for (int i = 0; i < N; i++){
		int cnt = 1;
		for (int j = v[i].size()-1; j >=0; j--){ //'ABC'��� C->B->A������
			int tmp = v[i][j] - 'A'; //0~25�� index�� ���ĺ� ���ڷ� �������ֱ�����
			alpha[tmp] += cnt;
			cnt *= 10; //�ڸ��� �ö󰥶����� 10������
		}
	}
	sort(alpha, alpha + 26); //��������
	int a = 9;
	for (int i = 25; i >=0; i--){
		if (alpha[i] != 0) {
			result += a*alpha[i]; //����ġ ū�ͺ��� 9�� �Űܼ� ����������
			a--;
		}
	}
	cout << result << endl;
}