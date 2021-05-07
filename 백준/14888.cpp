#include <iostream>
#include <vector>
#define INF 100000000
using namespace std;

int N; //���� ����
int arr[12];
int oper[4];  //��� ���� ������ ���� { '+','-','*','/' } 
vector<int> v; //(������ -> ���ڷ� �ٲ㼭 ����)
int visit[4]; //����� ������ ����
int maxR = -INF;
int minR=INF;

void solve(int cnt) {//cnt:������ ����
	if (cnt == N - 1) { //�������� : �����ڰ��� = ���ǰ���-1
		int result = arr[0];
		for (int i = 0; i < v.size(); i++){
			if (v[i] == 0) {
				result += arr[i + 1];
			}
			else if (v[i] == 1) {
				result -= arr[i + 1];
			}
			else if (v[i] == 2) {
				result *= arr[i + 1];
			}
			else if (v[i] == 3) {
				result /= arr[i + 1];
			}
		}
		if (result > maxR) maxR = result;
		if (result < minR) minR = result;
		return;
	}

	for (int i = 0; i < 4; i++){ //��Ʈ��ŷ
		if (visit[i] < oper[i]) { //������ ����
			visit[i]++;
			v.push_back(i); //�����ڸ� ��Ÿ���� ���ڸ� ����
			solve(cnt + 1);
			v.pop_back();
			visit[i]--;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){//����
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++){//�����ڰ���
		cin >> oper[i];
	}

	solve(0);
	cout << maxR << "\n" << minR;
}