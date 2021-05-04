#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int value[50][50]; //�� �̴��� ���� ���
int visit[9]; //���� ���ÿ���
vector<int> v;
int maxScore;

void solve(vector<int> order) {
	int tmp = 0; //����
	int cur = 0; //���° ����
	for (int i = 0; i < N; i++){	
		int out = 0;  //�ƿ�
		int one = 0; int two = 0; int three = 0; //1��,2��,3��
		while (out<3) {
			cur %= 9; //���� Ÿ��
			int result = value[i][order[cur]]; //���� ���� ���
			if (result == 0) out++; 
			else if (result == 1) { 
				tmp += three;
				three = two;
				two = one;
				one = 1;
			}
			else if (result == 2) {
				tmp += (three + two);
				three = one;
				two = 1;
				one = 0;
			}
			else if (result == 3) {
				tmp += (one + two + three);
				three = 1;
				one = 0; two = 0;
			}
			else {
				tmp += (one + two + three + 1);
				one = 0; two = 0; three = 0;
			}
			cur++; //���� Ÿ��
		}
	}
	maxScore = max(maxScore, tmp); //�ִ����
}

void MakeOrder() { 
	if (v.size() == 8) {
		vector<int> order;
		for (int i = 0; i < 8; i++){
			if (i == 3) order.push_back(0); //4��Ÿ�ڴ� 1������
			order.push_back(v[i]);
		}
		solve(order);
		return;
	}
	
	for (int i = 1; i < 9; i++) {
		if (!visit[i]) {
			v.push_back(i);
			visit[i] = 1;
			MakeOrder();
			v.pop_back();
			visit[i] = 0;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 9; j++) {
			cin >> value[i][j];
		}
	}
	MakeOrder();
	cout << maxScore;
}