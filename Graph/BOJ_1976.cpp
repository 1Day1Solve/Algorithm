#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int graph[201][201];
bool visited[201];
vector<int> tourList;


void bfs(){
    queue<int> q;
    
    q.push(tourList[0]);
    visited[tourList[0]] = true;

    while (!q.empty()){
        int x = q.front();
        q.pop();

        for (int i = 1; i <= N; i++){
            if (!visited[i] && graph[x][i] == 1){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    cin >> N >> M;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < M; i++){
        int city;
        cin >> city;

        tourList.push_back(city);
    }

    bfs();


    for (const auto& i: tourList){
        if (!visited[i])    {cout << "NO" << '\n'; return 0;}
    }

    cout << "YES" << '\n';

    return 0;
}