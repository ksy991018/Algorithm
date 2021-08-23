#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

int T, N;
string P,n; //�Լ� & �迭

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> P; cin >> N; cin >> n;
		deque<int> dq;
		bool dir = true; //������ ������ ����
		bool flag = true; //���� ����
		string temp="";
		for (int i = 1; i < n.size(); i++){ 
			if (n[i] == ',' || n[i]==']') {
				if(temp!="") dq.push_back(stoi(temp)); //str -> int
				temp = "";
			} else temp += n[i]; //�� ���ڸ� ���� �ƴ�
		}

		for (int i = 0; i < P.size(); i++){
			if (P[i] == 'R') { //���� ������
				dir = !dir;
			}
			else if (P[i] == 'D') { //����
				if (dq.empty()) {
					flag = false; //������
					break;
				}
				else {
					if (dir) dq.pop_front(); //������
					else dq.pop_back(); //������
				}
			}
		}
		if (!flag) cout << "error" << endl;
		else {
			if (!dir) reverse(dq.begin(), dq.end()); //�������̸� ������
			cout << "[";
			for (int i = 0; i < dq.size(); i++){
				if (i == dq.size() - 1) cout << dq[i];
				else cout << dq[i] << ",";
			}
			cout << "]" << endl;
		}
	}
}