#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int>b) {
	if (a.first != b.first) return a.first > b.first;
	else return a.second < b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	unordered_map<string, vector<pair<int, int>>> playList;
	unordered_map<string, int> allgenre;
	for (int i = 0; i < genres.size(); i++){
		playList[genres[i]].push_back({ plays[i],i });
		allgenre[genres[i]] += plays[i];
	}
	for (auto i = playList.begin(); i != playList.end(); i++){
		sort(i->second.begin(), i->second.end(),compare);
	}
	while (allgenre.size() > 0) {
		int maxPlay = 0;
		string best = "";
		for (auto i = allgenre.begin(); i != allgenre.end(); i++){
			if (maxPlay < i->second) {
				maxPlay = i->second;
				best = i->first;
			}
		}
		allgenre.erase(best);
		int cnt = 0;
		for (int i = 0; i < playList[best].size(); i++){
			answer.push_back(playList[best][i].second);
			if (i == 1) break;
		}
	}
	return answer;
}

int main() {
	vector<int> result = solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 });
	for (auto a : result) {
		cout << a << " ";
	}
}