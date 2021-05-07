#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int map[21][21];
int visit[21];
vector<int> v; //��ŸƮ�� 
int result=10000000;

void solve(int cur,int cnt) {
	if (cnt == N / 2) {
		vector<int> v2; //��ũ��
		for (int i = 1; i <=N; i++)
			if (!visit[i]) v2.push_back(i);
		
		int a=0, b=0; //�ɷ�ġ ��

		for (int i = 0; i < cnt-1; i++){
			for (int j = i + 1; j < cnt; j++) {
				a += (map[v[i]][v[j]]+ map[v[j]][v[i]]);
				b += (map[v2[i]][v2[j]] + map[v2[j]][v2[i]]);
			}
		}
		result = min(result, abs(a-b));
		return;
	}

	for (int i = cur+1; i <=N; i++){ //1�����ϸ� �ð��ʰ� --> ���ʿ��� �ߺ��߻�
		if (!visit[i]) {
			visit[i] = 1;
			v.push_back(i);
			solve(i,cnt + 1);
			visit[i] = 0;
			v.pop_back();
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <=N; i++){
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	solve(0,0);
	cout << result;
}