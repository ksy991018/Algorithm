#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//핵심: 택배 내리는 상황은 고려x(무게맞게 싣으면 무조건 내리기 때문에) 대신에 각 마을에서 트럭이 싣고있는 택배의 개수만 고려
//		받는 마을의 번호를 기준으로 오름차순 정렬(받는마을과 보내는마을의 차이가 작을수록 효율적)

int N, C; //마을 수, 트럭용량
int M; //박스 정보개수
vector<pair<pair<int, int>, int>> list; //택배 <<보내는마을,받는마을>,박스개수>
int truck[2001]; //마을별로 트럭에 싣고있는 택배개수 저장
int success; //최대 박스수

bool compare(pair<pair<int, int>, int> a ,pair<pair<int, int>, int> b) { //받는마을 기준으로 오름차순 정렬
	if (a.first.second == b.first.second) return a.first.first < b.first.first;
	else return a.first.second < b.first.second;
}

int main() {
	cin >> N >> C;
	cin >> M;

	for (int i = 0; i < M; i++){
		int sender, receiver, box;
		cin >> sender >> receiver >> box;
		list.push_back({ {sender,receiver},box });
	}
	sort(list.begin(), list.end(),compare);

	for (int i = 0; i < list.size(); i++){
		int from = list[i].first.first; //출발
		int to = list[i].first.second; //도착
		int size = list[i].second; //싣어야할 택배수
		int max_truck= 0; //현재 택배가 지나가야할 truck배열값중 가장큰거
		for (int j = from; j < to; j++){
			max_truck = max(truck[j], max_truck);
		}
		int capacity = min(size,C-max_truck);//가져갈수있는 택배수 구하기위한 변수 (원래 택배수,가능한공간)
		for (int j = from; j < to; j++) { //출발부터 도착전까지 가능한 택배수 할당
			truck[j] += capacity;
		}
		success += capacity; //트럭에 성공적으로 싣은 택배
	}
	cout << success;
}