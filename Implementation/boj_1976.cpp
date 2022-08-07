#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[201];
queue<int> bfs;
bool visited[201] = {false};
int plan[1000];
int N, M;

bool isConnected(int R1, int R2){
    bfs = queue<int>();
    fill(&visited[0], &visited[201], false);

    bfs.push(R1);
    visited[R1] = true;

    while(!bfs.empty()){
        if(bfs.front() == R2) return true;

        for(const int& i : graph[bfs.front()]) {
            if(!visited[i]) {
                bfs.push(i);
                visited[i] = true;
            }
        }

        bfs.pop();
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> N >> M;
    int input;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> input;
            if(input) graph[i+1].push_back(j+1);
        }
    }

    for(int i=0; i<M; i++){
        cin >> plan[i];
    }

    for(int i=0; i<M-1; i++){
        if(isConnected(plan[i], plan[i+1])) continue;
        else {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}