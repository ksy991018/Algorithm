#include <iostream>
#include<vector>
#include <queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int visit[100][100];

//bfs
int solution(vector<vector<int> > maps)
{
    int N = maps.size();
    int M = maps[0].size();
    queue<pair<int, int>>q;
    q.push({ 0,0 });
    visit[0][0] = 1;
    int answer = 0;

    while (!q.empty()) {
        int size = q.size();
        answer++;
        while (size--) {
            int x = q.front().first;
            int y = q.front().second;
            if (x == N - 1 && y == M - 1) return answer;
            q.pop();
            for (int i = 0; i < 4; i++){
                int cx = x + dx[i];
                int cy = y + dy[i];
                if (cx >= 0 && cx < N && cy >= 0 && cy < M && maps[cx][cy] && !visit[cx][cy]) {
                    visit[cx][cy] = 1;
                    q.push({ cx,cy });
                }
            }
        }      
    }
    return -1;
}

int main() {
    cout << solution({ {1, 0, 1, 1, 1},{1, 0, 1, 0, 1},{1, 0, 1, 1, 1},{1, 1, 1, 0, 1},{0, 0, 0, 0, 1} })<<endl;
    cout << solution({ { 1, 0, 1, 1, 1},{1, 0, 1, 0, 1},{1, 0, 1, 1, 1},{1, 1, 1, 0, 0},{0, 0, 0, 0, 1} }) << endl;

    
}