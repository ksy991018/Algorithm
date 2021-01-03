#include <iostream>
#define len 26
using namespace std;

struct Trie {
	Trie* next[len];
	bool finish;

	Trie() :finish(false) {
		for (int i = 0; i < len; i++){
			next[i] = NULL;
		}
	}

	~Trie() {
		for (int i = 0; i < len; i++){
			if(next[i]) delete next[i];
		}
	}
	void insert(const char* c) {
		if (*c == NULL) {
			finish = true;
		}
		else {
			int curr = *c - 'a';
			if (next[curr] == NULL) next[curr] = new Trie;
			next[curr]->insert(c + 1);
		}
	}
	bool find(const char* c) {
		if (*c == NULL) {
			if (finish) return true;
			return false;
		}
		int curr = *c - 'a';
		if (next[curr] == NULL) return false;
		return next[curr]->find(c + 1);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	Trie* root = new Trie();

	while (n--) {
		char s[505];
		cin >> s;
		root->insert(s);
	}
	while (m--) {
		char s[505];
		cin >> s;
		if (root->find(s)) cnt++;
	}
	cout << cnt << "\n";
	delete root;
}