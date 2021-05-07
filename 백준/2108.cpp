#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N,n;
int sum;
int visit[8001]; //�ش� �ε��� ��� �Է¹޾Ҵ���
vector<int> v; //�� �Է�
vector<pair<int, int>> cnt; //(�󵵼�, v������ ��ġ�ε���)
int result[4];

bool compare(pair<int,int> a, pair<int,int> b) { //�󵵼� ���� �������� ����
	if (a.first == b.first) return v[a.second] < v[b.second]; //���� �󵵼��� ������ �������� ����
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
		if (n < 0) n = abs(n) + 4000; //�����ϰ��
		visit[n]++;
	}
	
	if (flag) {
		sort(v.begin(), v.end());
		result[0] = round(sum / double(N)); //������
		result[1] = v[N / 2]; //�߾Ӱ�
		result[3] = v[v.size() - 1] - v[0]; //����

		for (int i = 0; i < N; i++) {
			int n = (v[i] < 0 ? abs(v[i])+4000 : v[i]);
			if (visit[n] > 1) {
				cnt.push_back({ visit[n],i });
				visit[n] = 0;
			}
		}
		if (cnt.size() == 0) result[2] = v[1]; //�󵵼� �� 1
		else {
			sort(cnt.begin(), cnt.end(), compare);
			if (cnt.size() == 1) result[2] = v[cnt[0].second];
			else result[2] = (cnt[0].first == cnt[1].first? v[cnt[1].second] : v[cnt[0].second]); 
			//������ �Ǿ� �ΰ��� �󵵼� ������, �ι�° ������ ���� �̿� (�ֺ��� �ι�°�� ������ �ǹ�)
		}
	}
	for (int i = 0; i < 4; i++){
		cout << result[i] << endl;
	}
}