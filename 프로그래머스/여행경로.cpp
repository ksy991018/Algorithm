#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<string>> result;

void dfs(string start, vector<vector<string>> tickets, vector<string> temp,vector<int> visit) {
	temp.push_back(start);
	if (temp.size() == tickets.size() + 1) {
		result.push_back(temp);
		return;
	}
	
	for (int i = 0; i < tickets.size(); i++){
		if (tickets[i][0] != start) continue;
		if (!visit[i]) {
			visit[i] = 1;
			dfs(tickets[i][1], tickets,temp,visit);
			visit[i] = 0;
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	vector<int> visit(tickets.size());
	sort(tickets.begin(), tickets.end());
	vector<string> temp;
	dfs("ICN",tickets,temp,visit);
	sort(result.begin(), result.end());
	answer = result[0];
	return answer;
}

int main() {
	//vector<string> result = solution({ {"ICN", "JFK"},{"HND", "IAD"},{"JFK", "HND"} });
	vector<string> result = solution({ {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL", "SFO"} });
}