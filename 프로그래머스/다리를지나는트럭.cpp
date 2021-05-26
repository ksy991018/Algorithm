#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<pair<int,int>> q;
	int curWeight = 0; //현재 다리에있는 트럭들 무게 

	for (int i = 0; i < truck_weights.size(); i++) {
		bool flag = true; //while문 한번도 실행안한경우 시간증감 위해 
		bool popflag = false; //현재상태에서 pop가능한지
		if (!q.empty()) {
			if (q.front().second + bridge_length == answer + 1) popflag = true;
		}
		while (popflag || curWeight + truck_weights[i] > weight) { //못넣는경우거나 pop가능한경우
			flag = false;
			answer++;
			if (q.front().second + bridge_length == answer) {	
				curWeight -= q.front().first;
				q.pop();
				popflag = false;
			}
		}
		if (flag) answer++; //while문 실행안한경우 
		q.push({ truck_weights[i],answer}); //트럭무게와 시간 
		curWeight += truck_weights[i];
	}

	while (!q.empty()) {
		answer++;
		if (q.front().second + bridge_length == answer) q.pop();
	}

	return answer;
}

int main() {
	//cout << solution(2, 10, { 7,4,5,6 }) <<endl;
	//cout << solution(100, 100, { 10 }) << endl;
	//cout << solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 }) <<endl;
	cout << solution(5, 5, { 2, 2, 2, 2, 1, 1, 1, 1, 1 }) << endl;
}