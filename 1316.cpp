#include<iostream>
#include <cstring>
using namespace std;

int N;
int arr[26];
int cnt;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		memset(arr, 0, sizeof(arr));
		string s;
		cin >> s;
		bool flag = true;
		arr[s[0] - 'a'] = 1;
		for (int i = 1; i <s.size(); i++){
			if (arr[s[i] - 'a'] != 0 && s[i - 1] != s[i]) {//���� �Է¹������� �ְ� �������ڿ� �ٸ��� 
				flag = false;
				break;
			} else arr[s[i] - 'a']++;
		}
		if (flag) cnt++;
	}
	cout << cnt;
}