#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

	string n;
	cin >> n;
	n += "-";

	vector<int> add;
	vector<int> minus;

	bool flag = false;
	int tmp=0;
	int part_sum = 0;
	int result = 0;
	for (int i = 0; i < n.size(); i++) {
		if (n[i] != '+' && n[i] != '-') {
			tmp = tmp * 10 + (n[i]-'0'); //char to int
		}
		else if (n[i] == '-') {
			part_sum += tmp;
			if (flag) {
				minus.push_back(part_sum);
			}
			else { 
				add.push_back(part_sum);
			}
			flag = true;
			tmp = 0;
			part_sum = 0;
		}
		else if (n[i] == '+') {
			part_sum += tmp;
			tmp = 0;
		}
	}

	for (int i : add) {
		cout <<  "add : " << i << " ";
		result += i;
	}
	cout << endl;
	for (int i : minus) {
		cout << "minus : " << i << " ";
		result -= i;
	}
	cout << result << endl;

}