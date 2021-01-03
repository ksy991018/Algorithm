#include <iostream>
#include <string>
#define MAX 10
using namespace std;

struct TRIE {
	TRIE* next[10];
	bool finish;

	TRIE() :finish(false) {
		for (int i = 0; i < MAX; i++) {
			next[i] = NULL;
		}
	}
	void insert(const char* c) { //"911"�̸� 9
		if (*c == NULL) {//���ڿ��� �������� finishǥ��
			finish = true;
			return;
		}
		int cur = *c - '0'; //str to int
		if (next[cur] == NULL) next[cur] = new TRIE; //���� ����� ��尡 ������ ��� ����, ������ �н�
		next[cur]->insert(c + 1); //c+1�ϸ� "11"�� ȣ��
	}
	bool flag() {
		for (int i = 0; i < MAX; i++){
			if (next[i] != NULL) {
				if (finish) return false; //�Էµ��� ���İ��� ��尡 ������
				if (!next[i]->flag()) return false; //�̹� �Է��� �����忡 �����ߴµ�, �� ����� �ڽĳ�� ����
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
