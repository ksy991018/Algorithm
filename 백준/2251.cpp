#include <iostream>
#include <queue>
using namespace std;

int visit[201][201]; //[첫번째물양][두번째물양]
int from[6] = { 0,0,1,1,2,2 }; //물 따르는 방법 6가지 : From[i] -> To[i]
int to[6] = { 1,2,0,2,0,1 };
int result[201]; //세번째 물통의 물의 양
int bottle[3]; //물통의 부피
queue<pair<int, int>> q;

int main() {
	for (int i = 0; i < 3; i++) {
		cin >> bottle[i];
	}

	//맨 처음 케이스
	result[bottle[2]] = 1;
	visit[0][0] = 1;
	q.push({ 0,0 });

	//bfs
	while (!q.empty()) {
		int one = q.front().first;
		int two = q.front().second;
		int three = bottle[2] - one - two; //고정된 양의 물
		q.pop();
		for (int i = 0; i < 6; i++){
			int cur[3] = { one,two,three };//각 물통의 물양

			cur[to[i]] += cur[from[i]]; //물 붓기
			cur[from[i]] = 0;
			if (cur[to[i]] > bottle[to[i]]) { //물이 넘친 경우
				cur[from[i]] = cur[to[i]] - bottle[to[i]];
				cur[to[i]] = bottle[to[i]];
			}
			if (!visit[cur[0]][cur[1]]) { //새로운 물 조합인 경우
				visit[cur[0]][cur[1]] = 1;
				q.push({ cur[0],cur[1] });
				if (cur[0] == 0) { //첫번째 물통 빈 경우
					result[cur[2]] = 1; //세번째 물통 양
				}
			}
		}
	}
	for (int i = 0; i <= bottle[2]; i++) {
		if(result[i]) cout << i << " ";
	}
}