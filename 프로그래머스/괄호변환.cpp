#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool check(string p) { //올바른 괄호 문자열 체크
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

    for (int i = 0; i < p.size(); i++) { //u를 균형잡인 괄호 문자열로 세팅
        if (p[i] == '(') L++;
        else R++;

        if (L == R) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }

    if (check(u)) return u + solution(v); //u가 올바른 괄호인경우
    else {
        string temp = "(" + solution(v) + ")";
        for (int i = 1; i < u.size() - 1; i++) { //u의 양끝을 뺀 문자열 뒤집어서 넣기
            if (u[i] == '(') temp += ')';
            else temp += '(';
        }
        return temp;
    }
}

int main() {
    cout << solution("()))((()") << endl;
}