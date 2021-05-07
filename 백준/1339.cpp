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
		for (int j = v[i].size()-1; j >=0; j--){ //'ABC'라면 C->B->A순서로
			int tmp = v[i][j] - 'A'; //0~25번 index에 알파벳 숫자로 지정해주기위해
			alpha[tmp] += cnt;
			cnt *= 10; //자리수 올라갈때마다 10곱해줌
		}
	}
	sort(alpha, alpha + 26); //오름차순
	int a = 9;
	for (int i = 25; i >=0; i--){
		if (alpha[i] != 0) {
			result += a*alpha[i]; //가중치 큰것부터 9로 매겨서 점점내려감
			a--;
		}
	}
	cout << result << endl;
}