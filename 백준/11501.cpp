#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int T;
int N;

//�տ������� Ž���ϸ鼭 �ִ��� ã�Ƶ�, �� �ڿ� ������ �ֽĵ��� �ٽ� ����Ⱦƾ���.
//�ں��� Ž���ؼ� ���� Ŀ���� ������ �ִ� ����. �۾�����, �ִ�-���簪��ŭ ������ ����.

int main() {
	cin >> T;
	while (T--) {
		vector<int> v;
		cin >> N;

		for (int i = 0; i < N; i++){
			int n;
			cin >> n;
			v.push_back(n);
		}

		reverse(v.begin(), v.end()); //�ں��� Ž��

		long long best = 0;  //�ִ�
		long long get = 0; //���� 

		for(int i = 0; i <v.size() ; i++){
			if (best < v[i]) best = v[i];
			else get += best - v[i];
		}
		cout << get << "\n";
	}
}