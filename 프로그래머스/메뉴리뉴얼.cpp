#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m; //<����,���ü�> : �ڽ��丮 �ĺ�

void Course(string original, string tmp, int index,int size) {//size��ŭ �̱�
	if (tmp.size() == size) m[tmp]++;
	
	for (int i = index; i < original.size(); i++){
		Course(original, tmp + original[i], i + 1, size);
	}
}

bool compare(pair<string, int> a, pair<string, int> b) { //���ü� �������� 
	return a.second > b.second;
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
	for (int i = 0; i < course.size(); i++){
		int size = course[i]; //���� �ڽ���
		m.clear();
		for (int j = 0; j < orders.size(); j++){
			sort(orders[j].begin(), orders[j].end());
			if(size<=orders[j].size()) Course(orders[j],"", 0,size);
		}
		if (m.size() == 0) continue; //������ ���� ���°��
		vector<pair<string, int>> v (m.begin(), m.end()); //map->vector�� ����
		sort(v.begin(), v.end(), compare);
		int largest = v[0].second;//���� ���� ���õ� Ƚ��
		if (largest >= 2) { //�ּ� 2���̻�
			for (int j = 0; j < v.size(); j++) {
				if (largest == v[j].second) answer.push_back(v[j].first);
				else break;
			}
		}
	}
	sort(answer.begin(), answer.end());
    return answer;
}

int main() {
	vector<string> a = solution({ "XYZ", "XWY", "WXA" }, { 2, 3, 4 });
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}