#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[8];
int visit[8];
vector<int> v;

void solve(int cur) {
	if (v.size() == M) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
		return;
	}
	
	for (int i = cur; i < N; i++) { //��Ʈ��ŷ.
		if (!visit[i]) {
			visit[i] = 1;
			v.push_back(arr[i]);
			solve(i+1);
			v.pop_back();
			visit[i] = 0;
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr,arr+N); //�������� ���Ĺ̸� �ϸ� �Ŀ� ������ �ʿ����

	solve(0);
}