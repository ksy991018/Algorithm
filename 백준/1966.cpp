#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N; //testcase�ݺ�Ƚ��
int num; //��������
int choice; //�ñ��� ������ġ
int importance; //�߿䵵
int order; //���°�� �μ�
int front; //ť�� ù��° ����

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> num >> choice; 
		queue<int> q; //�߿䵵 ���ʴ�� ���� ť
		vector<int> v(10); //�߿䵵 ũ��� ���� ����
		for (int i = 0; i < num; i++){
			cin >> importance;
			v.push_back(importance);
			q.push(importance);
		}
		sort(v.begin(), v.end()); //�߿䵵 �������� ����
		order = 0; 

		while(true) {
			front = q.front(); //q�� �Ǿ� �ӽ�����
			q.pop();

			//v�� ���������Ұ� ���� q�� ����ִ� �߿䵵�� ���� ŭ
			if (front == v[v.size()-1]) { //���� �������� ���� ū �߿䵵�� ��� 
				order++;
				v.pop_back(); //����

				if (choice == 0) { //�����Ȱ� �ñ��� �������� ��� Ż��
					break;
				}
				else { //�ƴѰ��, �ñ��� ������ ��ġ����
					choice--;
				}
			}
			else { //���� �������� ū �߿䵵�� �ڿ��ִ� ���
				q.push(front); //�ӽ� �����س��� front�� �ٽ� ����
				if (choice == 0) { //�ñ��� ���� ��ġ�� �Ǿ��̸� �ǵڷ� ����
					choice += q.size() - 1;
				}
				else {
					choice--;
				}
			}
		}
		cout << order << endl;
	}
}