#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    queue<int> q;
    bool visited[200] = { false };
    int answer = 0;
    
    for (int i=0; i<n; i++){
        if (visited[i]) continue;
        else {
            q.push(i);
            while(!q.empty()){
                for (int j=0; j<n; j++){
                    if(visited[j] ||
                       !computers[q.front()][j])
                        continue;
                    q.push(j);
                    visited[j] = true;
                }
                q.pop();
            }
            answer++;
        }
    }
    
    return answer;
}