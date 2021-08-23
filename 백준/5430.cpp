#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

int T, N;
string P,n; //함수 & 배열

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> P; cin >> N; cin >> n;
		deque<int> dq;
		bool dir = true; //정방향 역방향 여부
		bool flag = true; //정상 여부
		string temp="";
		for (int i = 1; i < n.size(); i++){ 
			if (n[i] == ',' || n[i]==']') {
				if(temp!="") dq.push_back(stoi(temp)); //str -> int
				temp = "";
			} else temp += n[i]; //꼭 한자리 숫자 아님
		}

		for (int i = 0; i < P.size(); i++){
			if (P[i] == 'R') { //방향 뒤집기
				dir = !dir;
			}
			else if (P[i] == 'D') { //빼기
				if (dq.empty()) {
					flag = false; //비정상
					break;
				}
				else {
					if (dir) dq.pop_front(); //정방향
					else dq.pop_back(); //역방향
				}
			}
		}
		if (!flag) cout << "error" << endl;
		else {
			if (!dir) reverse(dq.begin(), dq.end()); //역방향이면 뒤집기
			cout << "[";
			for (int i = 0; i < dq.size(); i++){
				if (i == dq.size() - 1) cout << dq[i];
				else cout << dq[i] << ",";
			}
			cout << "]" << endl;
		}
	}
}