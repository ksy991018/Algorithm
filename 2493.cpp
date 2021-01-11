#include <iostream>
#include <stack>
using namespace std;

int N;
int n;
stack<pair<int,int>> s; //(��ġ,��)

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++){
		cin >> n;
		
		while (!s.empty()) { //��ó���̰ų�, ���̻� ���� ������ ���� ���

			if (n > s.top().second) { //���� ������ ������ top�� ������, ������ top����. ���̻� ����ž �ɼ� ���� ����. 
				s.pop();
			}
			else { //���� ������ ������ top�� ������(����ž �߰�), ������ top ��ġ��� �� ����
				cout << s.top().first << " ";
				break;
			}
		}

		if (s.empty()) { //����ž ������
			cout << "0" << " ";
		}

		s.push(make_pair(i, n)); //���� (��ġ,����) ���ÿ� �߰�.
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