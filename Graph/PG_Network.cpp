#include <string>
#include <vector>

using namespace std;

bool visited[200];

bool dfs(int n, int start, const vector<vector<int>>& computers){
    if (visited[start])     return false;
    visited[start] = true;
    
    for (int i = 0; i < n; i++){
        // 방문한 적 없고 연결되어 있는 노드
        if (computers[start][i] == 1 && visited[i] == false)
            dfs(n, i, computers);
    }
    
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++){
        if (dfs(n, i, computers) == true)   answer++;
    }
    
    return answer;
}