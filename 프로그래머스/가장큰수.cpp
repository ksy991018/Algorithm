#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a,string b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> tmp;
	for (auto v : numbers) {
		tmp.push_back(to_string(v));
	}
	sort(tmp.begin(), tmp.end(),compare);
	if (tmp[0].at(0) == '0') return "0";
	else {
		for (auto v : tmp)
			answer += v;
	}
	return answer;
}

int main() {
	cout << solution({ 6,10,2 });
}