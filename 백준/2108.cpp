#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N,n;
int sum;
int visit[8001]; //해당 인덱스 몇번 입력받았는지
vector<int> v; //수 입력
vector<pair<int, int>> cnt; //(빈도수, v에서의 위치인덱스)
int result[4];

bool compare(pair<int,int> a, pair<int,int> b) { //빈도수 기준 내림차순 정렬
	if (a.first == b.first) return v[a.second] < v[b.second]; //같은 빈도수면 값기준 오름차순 정렬
	else return a.first > b.first;
}
int main() {
	cin >> N;
	bool flag = true;
	for (int i = 0; i < N; i++){
		cin >> n;
		if (N == 1) {
			result[0] = n; result[1] = n; result[2] = n; result[3] = 0;
			flag = false;
			break;
		}
		sum += n;
		v.push_back(n);
		if (n < 0) n = abs(n) + 4000; //음수일경우
		visit[n]++;
	}
	
	if (flag) {
		sort(v.begin(), v.end());
		result[0] = round(sum / double(N)); //산술평균
		result[1] = v[N / 2]; //중앙값
		result[3] = v[v.size() - 1] - v[0]; //범위

		for (int i = 0; i < N; i++) {
			int n = (v[i] < 0 ? abs(v[i])+4000 : v[i]);
			if (visit[n] > 1) {
				cnt.push_back({ visit[n],i });
				visit[n] = 0;
			}
		}
		if (cnt.size() == 0) result[2] = v[1]; //빈도수 다 1
		else {
			sort(cnt.begin(), cnt.end(), compare);
			if (cnt.size() == 1) result[2] = v[cnt[0].second];
			else result[2] = (cnt[0].first == cnt[1].first? v[cnt[1].second] : v[cnt[0].second]); 
			//정렬후 맨앞 두개의 빈도수 같으면, 두번째 순서의 원소 이용 (최빈값중 두번째로 작은수 의미)
		}
	}
	for (int i = 0; i < 4; i++){
		cout << result[i] << endl;
	}
}