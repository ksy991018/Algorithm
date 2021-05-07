#include <iostream>
#include <string>
#define MAX 10
using namespace std;

//트라이 알고리즘사용
//여러개의 문자열을 가지고 있을때, 어떤 문자열이 그 문자열 중 하나인지 알아내는 방법

struct TRIE {
	TRIE* next[10]; //전화번호 10자리
	bool finish; //문자열의 끝 표시

	TRIE() :finish(false) {//생성자
		for (int i = 0; i < MAX; i++) {
			next[i] = NULL; //처음에는 널로 초기화
		}
	}

	void insert(const char* c) { //"911"이면 9
		if (*c == NULL) {//종료시점.  문자열의 마지막에 널문자 존재. 
			finish = true; //문자열이 끝났으면 finish표시
			return;
		}
		int cur = *c - '0'; //str to int
		if (next[cur] == NULL) next[cur] = new TRIE; //현재 연결된 노드가 없으면 노드 생성, 있으면 패스
		next[cur]->insert(c + 1); //재귀문 c+1하면 "11"이 호출
	}

	bool flag() {
		for (int i = 0; i < MAX; i++){
			if (next[i] != NULL) {
				//번호가 다른번호의 접두어인 경우
				if (finish) return false; //입력도중 거쳐가는 노드가 종료노드
				if (!next[i]->flag()) return false; //이번 입력의 종료노드에 도착했는데, 그 노드의 자식노드 존재
			}
		}
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		TRIE* root = new TRIE();
		bool flag = true;
		for (int i = 0; i < N; i++) {
			char num[11];
			cin >> num;
			root->insert(num);
		}
		//일관성있는 목록 확인
		if (root->flag()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}



//#include <iostream>
//#include <string>
//#define MAX 10
//using namespace std;
//
//struct TRIE {
//	TRIE* next[10];
//	bool finish;
//	bool child;
//
//	TRIE() :finish(false),child(false){
//		for (int i = 0; i <MAX ; i++){
//			next[i] = NULL;
//		}
//	}
//
//	~TRIE() {
//		for (int i = 0; i < MAX; i++){
//			if (next[i] != NULL) {
//				delete next[i];
//			}
//		}
//	}
//
//	bool insert(const char* c) {
//		if (*c == NULL) {
//			finish = true;
//			return child;
//		}
//		int cur = *c - '0'; //str to int
//		if (next[cur] == NULL) {
//			next[cur] = new TRIE;
//		}
//		child = true;
//		return finish || next[cur]->insert(c + 1);
//	} 
//};
//
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int T;
//	cin >> T;
//	for (int i = 0; i < T; i++){
//		int N;
//		cin >> N;
//		TRIE* root = new TRIE();
//		bool flag=true;
//		for (int i = 0; i < N; i++){
//			char num[11];
//			cin >> num;
//			if (root->insert(num) && flag) {
//				flag = false;
//			}
//		}
//		if (flag) {
//			cout << "YES" << "\n";
//		}
//		else {
//			cout << "NO" << "\n";
//		}
//		delete root;
//	}
//}
