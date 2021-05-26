#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<pair<int,int>> q;
	int curWeight = 0; //���� �ٸ����ִ� Ʈ���� ���� 

	for (int i = 0; i < truck_weights.size(); i++) {
		bool flag = true; //while�� �ѹ��� ������Ѱ�� �ð����� ���� 
		bool popflag = false; //������¿��� pop��������
		if (!q.empty()) {
			if (q.front().second + bridge_length == answer + 1) popflag = true;
		}
		while (popflag || curWeight + truck_weights[i] > weight) { //���ִ°��ų� pop�����Ѱ��
			flag = false;
			answer++;
			if (q.front().second + bridge_length == answer) {	
				curWeight -= q.front().first;
				q.pop();
				popflag = false;
			}
		}
		if (flag) answer++; //while�� ������Ѱ�� 
		q.push({ truck_weights[i],answer}); //Ʈ�����Կ� �ð� 
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