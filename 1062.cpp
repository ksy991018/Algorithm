#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K; //총 단어 개수 , 가르치는 글자개수
int visit[26]; //알파벳 배움 여부
vector<string> v; //단어들
int result; //최대 읽을수 있는 단어

void solve(int alpha,int cnt) { //배울 글자, 배운 글자수
	if (cnt == K) { 
		int cnt = 0; //현재 조건에서 읽을수 있는 단어수
		for (int i = 0; i < v.size(); i++) { //각 단어 읽을수있는지 없는지 판단
			bool flag = true;
			for (int j = 0; j < v[i].size(); j++) {
				int current = v[i][j] - 'a';
				if (!visit[current]) { //못읽는 문자 있으면 종료
					flag = false;
					break;
				}
			}
			if (flag) cnt++;
		}
		result = max(result, cnt);
		return;
	}

	//브루트포스
	for (int i = alpha; i < 26; i++){
		if (!visit[i]) {//단어 안배웠으면 
			visit[i] = 1;
			solve(i, cnt + 1);
			visit[i] = 0;
		}
	}
}
int main() {
	cin >> N >> K;
	K-= 5; //"anta + tica -> a,n,t,i,c"

	visit['a' - 'a'] = 1;
	visit['n' - 'a'] = 1;
	visit['t' - 'a'] = 1;
	visit['i' - 'a'] = 1;
	visit['c' - 'a'] = 1;

	for (int i = 0; i < N; i++){
		string s;
		cin >> s;
		s = s.substr(4, s.size()-8); //anta다음 글자부터 tica전 글자까지
		string tmp = "";
		for (int i = 0; i < s.size(); i++){
			if (!visit[s[i] - 'a']) { //a,n,t,i,c빼기 
				tmp += s[i];
			}
		}
		if (tmp == "") result++; //a,n,t,i,c로만 이루어져있으면 셀수있음
		v.push_back(tmp);
	}
	if (K < 0) cout << 0; //a,n,t,i,c조차 못셀경우
	else {
		solve(0, 0);
		cout << result;
	}
	
}