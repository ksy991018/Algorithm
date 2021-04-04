#include <iostream>
using namespace std;

int N, K;
int map[200]; //컨베이어 벨트 
int robot[100]; //로봇유무
int result; //단계

bool isValid() {//내구도 0인거 K개이상인지
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
		int tmp = map[2*N-1]; //컨베이어벨트 한칸 이동
		for (int i = 2*N-1; i>=1 ; i--) map[i] = map[i - 1];
		map[0] = tmp;

		for (int i = N-1; i >=0; i--){ //컨베이어 벨트따라 로봇도 이동
			if (i == N - 1 && robot[i]) robot[i] = 0; //내리는 지점
			else if (robot[i]) {
				robot[i] = 0;
				robot[i + 1] = 1;
			}
		}
		for(int i = N-1; i >=0; i--){ //이동가능한 로봇만 이동
			if (i == N - 1 && robot[i]) robot[i] = 0; //내리는지점
			else if (robot[i] && map[i+1]>=1 && !robot[i+1]) {
				robot[i] = 0;
				robot[i + 1] = 1;
				map[i + 1]--; //내구도 줄이기
			}
		}

		if (map[0]>0) { //올리는 지점 가능할때
			robot[0] = 1;
			map[0]--;
		}
	}
	cout << result;
}