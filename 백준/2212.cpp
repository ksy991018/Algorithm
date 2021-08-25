#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K,n;
int result = 0;
vector<int> sensor;
int visit[10000];
vector<pair<int,int>> diff;
vector<int> v;

bool compare(pair<int, int> a, pair<int, int> b) { //내림차순 정렬
	if (a.first == b.first) return a.second < b.second;
	else return a.first > b.first;
}

void solve() {
	for (int i = 0; i < sensor.size() - 1; i++) {
		int gap = sensor[i + 1] - sensor[i];
		diff.push_back({ gap,i + 1 }); //{차이, 기준 인덱스} 
	}
	sort(diff.begin(), diff.end(), compare); //인접한 센서의 차이가 큰거 기준으로 나누기 
	for (int i = 0; i < K-1; i++){
		v.push_back(diff[i].second); //기준점의 시작 인덱스
	}
	sort(v.begin(), v.end());

	int tmpIndex = 0;
	for (int i = 0; i < v.size(); i++){ //구간합 구하기
		result += sensor[v[i]-1] - sensor[tmpIndex];
		tmpIndex = v[i];
	}
	result += sensor[N - 1] - sensor[tmpIndex];
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++){
		cin >> n;
		sensor.push_back(n);
	}
	sort(sensor.begin(), sensor.end()); //센서 정렬 


	if (sensor.size() <= K) result = 0; //집중국이 각 센서 맡을수 있으면
	else solve();

	cout << result << endl;
}