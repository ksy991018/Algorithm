#include <iostream>
using namespace std;

int N, K;
int map[200]; //�����̾� ��Ʈ 
int robot[100]; //�κ�����
int result; //�ܰ�

bool isValid() {//������ 0�ΰ� K���̻�����
	int cnt = 0;
	for (int i = 0; i < 2*N; i++){
		if(map[i]==0) cnt++;
	}
	if (cnt >= K) return false;
	else return true;
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < 2*N; i++) cin >> map[i];
	
	while (isValid()) {
		result++;
		int tmp = map[2*N-1]; //�����̾Ʈ ��ĭ �̵�
		for (int i = 2*N-1; i>=1 ; i--) map[i] = map[i - 1];
		map[0] = tmp;

		for (int i = N-1; i >=0; i--){ //�����̾� ��Ʈ���� �κ��� �̵�
			if (i == N - 1 && robot[i]) robot[i] = 0; //������ ����
			else if (robot[i]) {
				robot[i] = 0;
				robot[i + 1] = 1;
			}
		}
		for(int i = N-1; i >=0; i--){ //�̵������� �κ��� �̵�
			if (i == N - 1 && robot[i]) robot[i] = 0; //����������
			else if (robot[i] && map[i+1]>=1 && !robot[i+1]) {
				robot[i] = 0;
				robot[i + 1] = 1;
				map[i + 1]--; //������ ���̱�
			}
		}

		if (map[0]>0) { //�ø��� ���� �����Ҷ�
			robot[0] = 1;
			map[0]--;
		}
	}
	cout << result;
}