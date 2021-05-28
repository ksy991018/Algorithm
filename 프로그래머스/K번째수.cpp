#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (int i = 0; i < commands.size(); i++) {
		vector<int> tmp;
		for (int k = commands[i][0] - 1; k < commands[i][1]; k++) {
			tmp.push_back(array[k]);
		}
		sort(tmp.begin(), tmp.end());
		answer.push_back(tmp[commands[i][2] - 1]);
	}
	return answer;
}