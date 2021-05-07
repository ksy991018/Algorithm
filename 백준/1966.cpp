#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N; //testcase반복횟수
int num; //문서갯수
int choice; //궁금한 문서위치
int importance; //중요도
int order; //몇번째로 인쇄
int front; //큐의 첫번째 원소

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> num >> choice; 
		queue<int> q; //중요도 차례대로 넣을 큐
		vector<int> v(10); //중요도 크기비교 위한 벡터
		for (int i = 0; i < num; i++){
			cin >> importance;
			v.push_back(importance);
			q.push(importance);
		}
		sort(v.begin(), v.end()); //중요도 오름차순 정렬
		order = 0; 

		while(true) {
			front = q.front(); //q의 맨앞 임시저장
			q.pop();

			//v의 마지막원소가 현재 q에 들어있는 중요도중 가장 큼
			if (front == v[v.size()-1]) { //현재 문서도가 가장 큰 중요도인 경우 
				order++;
				v.pop_back(); //삭제

				if (choice == 0) { //삭제된게 궁금한 문서였던 경우 탈출
					break;
				}
				else { //아닌경우, 궁금한 문서의 위치변경
					choice--;
				}
			}
			else { //현재 문서보다 큰 중요도가 뒤에있는 경우
				q.push(front); //임시 저장해놓은 front를 다시 넣음
				if (choice == 0) { //궁금한 문서 위치가 맨앞이면 맨뒤로 변경
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