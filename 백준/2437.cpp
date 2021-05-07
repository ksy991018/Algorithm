#include <iostream>
#include <queue>
using namespace std;

int N; //저울추 개수
priority_queue<int,vector<int>,greater<int>> pq; //오름차순 정렬
int total; //의미 : total까지 무게측정가능

//아이디어 : 오름차순 정렬 후 i-1번째까지 누적합은 첫번째 추부터 i-1번까지 추를 이용해 만들수 있는 최대 무게
//만약, i번째 추 무게가 (i-1번째까지의 누적합+1)보다 크다면 (i-1번째까지의 누적합+1)을 만들수있는 방법이 없음.

//total 변수 연산방법(조건 만족시 total+value[i])
//total(i-1까지 누적합) = 5, value(i번째추) = 6이면 (6+1,6+2,6+3,6+4,6+5=11) total=11까지 만들수있음.

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		pq.push(n);
	}

	while (N--) {
		int value = pq.top();
		pq.pop();
		if (value > total + 1) break; //total+1보다 현재 선택한 추가 크면 total+1를 잴수있는 방법이 없어짐.(total까지는 측정가능)
		else total += value; //누적합
	}
	cout << total + 1;
}