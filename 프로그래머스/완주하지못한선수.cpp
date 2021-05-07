#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	unordered_map<string, int> m;
	for (auto c : completion) {
		m[c]++; //default´Â 0
	}
	for (auto p : participant) {
		m[p]--;
		if (m[p] < 0) return p;
	}
}

int main() {
	cout << solution({ "mislav", "stanko", "mislav", "ana" }, { "stanko", "ana", "mislav" });
}