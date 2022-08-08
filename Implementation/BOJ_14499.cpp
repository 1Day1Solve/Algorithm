#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, M, x, y, K;
int graph[21][21];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main(){
    vector<int> moves;
    map<int, int> dice;

    cin >> N >> M >> x >> y >> K;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < K; i++){
        int move;
        cin >> move;

        moves.push_back(move);
    }

    for (int i = 1; i <= 6; i++)        dice[i] = 0;

    x++; y++;

    for (const auto& i: moves){
        int nx = x + dx[i - 1];
        int ny = y + dy[i - 1];
        map<int, int> ndice(dice);

        if (nx < 1 || nx > N || ny < 1 || ny > M)       continue;
        
        switch(i){
            case 1: // 동쪽으로 이동
                dice[1] = ndice[4];
                dice[3] = ndice[1];
                dice[4] = ndice[6];
                dice[6] = ndice[3];
                break;
            case 2: // 서쪽으로 이동
                dice[1] = ndice[3];
                dice[4] = ndice[1];
                dice[3] = ndice[6];
                dice[6] = ndice[4];
                break;
            case 3:
                dice[2] = ndice[1];
                dice[1] = ndice[5];
                dice[5] = ndice[6];
                dice[6] = ndice[2];
                break;
            case 4: // 남쪽으로 이동
                dice[1] = ndice[2];
                dice[5] = ndice[1];
                dice[2] = ndice[6];
                dice[6] = ndice[5];
                break;
        }

        if (graph[nx][ny] == 0){
            graph[nx][ny] = dice[6];
        }
        else {
            dice[6] = graph[nx][ny];
            graph[nx][ny] = 0;
        }

        x = nx;
        y = ny;

        cout << dice[1] << '\n';
    }


    return 0;
}