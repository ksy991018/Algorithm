#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K; //�� �ܾ� ���� , ����ġ�� ���ڰ���
int visit[26]; //���ĺ� ��� ����
vector<string> v; //�ܾ��
int result; //�ִ� ������ �ִ� �ܾ�

void solve(int alpha,int cnt) { //��� ����, ��� ���ڼ�
	if (cnt == K) { 
		int cnt = 0; //���� ���ǿ��� ������ �ִ� �ܾ��
		for (int i = 0; i < v.size(); i++) { //�� �ܾ� �������ִ��� ������ �Ǵ�
			bool flag = true;
			for (int j = 0; j < v[i].size(); j++) {
				int current = v[i][j] - 'a';
				if (!visit[current]) { //���д� ���� ������ ����
					flag = false;
					break;
				}
			}
			if (flag) cnt++;
		}
		result = max(result, cnt);
		return;
	}

	//���Ʈ����
	for (int i = alpha; i < 26; i++){
		if (!visit[i]) {//�ܾ� �ȹ������ 
			visit[i] = 1;
			solve(i, cnt + 1);
			visit[i] = 0;
		}
	}
}
int main() {
	cin >> N >> K;
	K-= 5; //"anta + tica -> a,n,t,i,c"

	visit['a' - 'a'] = 1;
	visit['n' - 'a'] = 1;
	visit['t' - 'a'] = 1;
	visit['i' - 'a'] = 1;
	visit['c' - 'a'] = 1;

	for (int i = 0; i < N; i++){
		string s;
		cin >> s;
		s = s.substr(4, s.size()-8); //anta���� ���ں��� tica�� ���ڱ���
		string tmp = "";
		for (int i = 0; i < s.size(); i++){
			if (!visit[s[i] - 'a']) { //a,n,t,i,c���� 
				tmp += s[i];
			}
		}
		if (tmp == "") result++; //a,n,t,i,c�θ� �̷���������� ��������
		v.push_back(tmp);
	}
	if (K < 0) cout << 0; //a,n,t,i,c���� �������
	else {
		solve(0, 0);
		cout << result;
	}
	
}