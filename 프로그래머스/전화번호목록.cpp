#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	unordered_map<string, int> map;

	for (int i = 0; i < phone_book.size(); i++){
		map[phone_book[i]] = 1;
	}

	for (int i = 0; i < phone_book.size(); i++){
		string tmp = "";
		for (int j = 0; j < phone_book[i].size(); j++) {
			tmp += phone_book[i][j];
			if (map[tmp] && tmp != phone_book[i]) return false;
		}
	}

	return answer;
}

int main() {
	vector<string> v = { "531", "97674223", "1195524421" };
	for (int i = 0; i < v.size(); i++){
		cout << v[i];
	}
}