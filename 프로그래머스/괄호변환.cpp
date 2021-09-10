#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool check(string p) { //�ùٸ� ��ȣ ���ڿ� üũ
    stack<int> s;
    for (int i = 0; i < p.size(); i++){
        if (p[i] == '(') s.push(1);
        else {
            if (s.empty()) return false;
            else s.pop();
        }
    }
    return true;
}

string solution(string p) {
    if (p=="" || check(p)) return p;
    
    int L = 0, R = 0; 
    string u, v;

    for (int i = 0; i < p.size(); i++) { //u�� �������� ��ȣ ���ڿ��� ����
        if (p[i] == '(') L++;
        else R++;

        if (L == R) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }

    if (check(u)) return u + solution(v); //u�� �ùٸ� ��ȣ�ΰ��
    else {
        string temp = "(" + solution(v) + ")";
        for (int i = 1; i < u.size() - 1; i++) { //u�� �糡�� �� ���ڿ� ����� �ֱ�
            if (u[i] == '(') temp += ')';
            else temp += '(';
        }
        return temp;
    }
}

int main() {
    cout << solution("()))((()") << endl;
}