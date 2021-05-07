#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> q;
	for (int i = 0; i < progresses.size(); i++){
		if ((100 - progresses[i]) % speeds[i] == 0) q.push((100 - progresses[i]) / speeds[i]);
		else q.push((100 - progresses[i]) / speeds[i] + 1);
	}
	int tmp = 0;
	while (!q.empty()) {
		tmp = q.front();
		int cnt = 0;
		while (!q.empty() && q.front() <= tmp) {
			cnt++;
			q.pop();
		}
		answer.push_back(cnt);
	}
	return answer;
}

int main() {
	vector<int> v = solution({ 93, 30, 55 }, { 1, 30, 5 });
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}