#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	int num;
	string group_name;
	map<string, string> mem_group; //key:����̸�,value:�׷��
	map<string, vector<string>> group_mem; //key:�׷��, value:��������� vec

	for (int i = 0; i < n; i++) {
		cin >> group_name;
		cin >> num;
		vector<string> members;
		string member;
		for (int j = 0; j < num; j++) {
			cin >> member;
			members.push_back(member);
			mem_group.insert(make_pair(member, group_name));
		}
		sort(members.begin(), members.end());
		group_mem.insert(make_pair(group_name, members));
	}

	string quiz;
	int choice;
	for (int i = 0; i < m; i++){
		cin >> quiz;
		cin >> choice;
		if (choice == 1) {//�׷��̸� ã��
			cout << mem_group[quiz] << endl;
		}
		else if (choice == 0) { //�ش�׷� �����ã��
			for (auto elem : group_mem[quiz]) {
				cout << elem << endl;
			}
		}
	}

}