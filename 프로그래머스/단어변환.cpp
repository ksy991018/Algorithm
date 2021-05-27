#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(string begin, string target, vector<string> words) {
	if (find(words.begin(), words.end(), target) == words.end()) return 0; //words에 target없는 경우 

	int answer = 0;
	queue<pair<string, int>> q;
	int visit[51] = { 0, };
	q.push({ begin,0 });
	while (!q.empty()) {
		string curWord = q.front().first;
		int n = q.front().second;
		q.pop();
		if (curWord == target) {
			answer = n;
			break;
		}	
		for (int i = 0; i < words.size(); i++){
			if (visit[i]) continue;
			int diff = 0;
			
			for (int j = 0; j < curWord.size(); j++) if (curWord[j] != words[i][j]) diff++;
			if (diff == 1) {
				visit[i] = 1;
				q.push({ words[i],n + 1 });	
			}
		}
	}
	return answer;
}

int main() {
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
}