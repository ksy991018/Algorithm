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

bool compare(pair<int, int> a, pair<int, int> b) { //�������� ����
	if (a.first == b.first) return a.second < b.second;
	else return a.first > b.first;
}

void solve() {
	for (int i = 0; i < sensor.size() - 1; i++) {
		int gap = sensor[i + 1] - sensor[i];
		diff.push_back({ gap,i + 1 }); //{����, ���� �ε���} 
	}
	sort(diff.begin(), diff.end(), compare); //������ ������ ���̰� ū�� �������� ������ 
	for (int i = 0; i < K-1; i++){
		v.push_back(diff[i].second); //�������� ���� �ε���
	}
	sort(v.begin(), v.end());

	int tmpIndex = 0;
	for (int i = 0; i < v.size(); i++){ //������ ���ϱ�
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
	sort(sensor.begin(), sensor.end()); //���� ���� 


	if (sensor.size() <= K) result = 0; //���߱��� �� ���� ������ ������
	else solve();

	cout << result << endl;
}