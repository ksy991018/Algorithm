#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int T;
int N;

//앞에서부터 탐색하면서 최댓값을 찾아도, 그 뒤에 나오는 주식들은 다시 사고팔아야함.
//뒤부터 탐색해서 값이 커지는 순간에 최댓값 갱신. 작아지면, 최댓값-현재값만큼 이익을 얻음.

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

		reverse(v.begin(), v.end()); //뒤부터 탐색

		long long best = 0;  //최댓값
		long long get = 0; //이익 

		for(int i = 0; i <v.size() ; i++){
			if (best < v[i]) best = v[i];
			else get += best - v[i];
		}
		cout << get << "\n";
	}
}