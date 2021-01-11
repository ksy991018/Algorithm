#include <iostream>
#include <stack>
using namespace std;

int N;
int n;
stack<pair<int,int>> s; //(위치,값)

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++){
		cin >> n;
		
		while (!s.empty()) { //맨처음이거나, 더이상 비교할 스택이 없을 경우

			if (n > s.top().second) { //현재 값보다 스택의 top이 낮으면, 스택의 top제거. 더이상 수신탑 될수 없기 때문. 
				s.pop();
			}
			else { //현재 값보다 스택의 top이 높으면(수신탑 발견), 스택의 top 위치출력 후 종료
				cout << s.top().first << " ";
				break;
			}
		}

		if (s.empty()) { //수신탑 없을때
			cout << "0" << " ";
		}

		s.push(make_pair(i, n)); //현재 (위치,높이) 스택에 추가.
	}
}



//int N;
//stack<int>s1;
//stack<int>res;
//int main() {
//
//	cin >> N;
//	for (int i = 0; i < N; i++){
//		int n;
//		cin >> n;
//		s1.push(n);
//	}
//
//	for (int i = 1; i < N; i++){
//		int top = s1.top(); 
//		bool flag = false;
//		s1.pop();
//		int cnt = s1.size(); 
//		stack<int>s2;
//		while(!s1.empty()){
//			if (top < s1.top()) {
//				flag = true;
//				break;
//			}
//			else {
//				s2.push(s1.top());
//				s1.pop();
//				cnt--;
//			}
//		}
//		while (!s2.empty()) {
//			s1.push(s2.top());
//			s2.pop();
//		}
//		if (!flag) {
//			cnt = 0;
//		}
//		res.push(cnt);
//	}
//	res.push(0);
//	while (!res.empty()) {
//		cout << res.top() << " ";
//		res.pop();
//	}
//}