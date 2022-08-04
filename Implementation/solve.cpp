#include <iostream>
#include <queue>
using namespace std;

int board[100][100] = { 0,};        //0은 빈공간, 1은 뱀, 2는 사과
int N, sec = 1;
queue<pair<int, char>> rot;
queue<pair<int, int>> snake;
int head[3] = {0, 0, 1};                        //x, y, 방향(상0 하2 좌3 우1)

int move(){
    switch(head[2]){
        case 0:
            if(head[0] < 1 || board[head[0] - 1][head[1]] == 1) return 0;
            else head[0]--;
            break;
        case 1:
            if(head[1] > N - 2 || board[head[0]][head[1] + 1] == 1) return 0;
            else head[1]++;
            break;
        case 2:
            if(head[0] > N - 2 || board[head[0] + 1][head[1]] == 1) return 0;
            else head[0]++;
            break;
        case 3:
            if(head[1] < 1 || board[head[0]][head[1] - 1] == 1) return 0;
            else head[1]--;
            break;
    }

    snake.push(pair<int, int>(head[0],head[1]));

    if(board[head[0]][head[1]] == 0) {
        board[snake.front().first][snake.front().second] = 0;
        snake.pop();
    }

    board[head[0]][head[1]] = 1;
    /*
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cout << board[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
    */

    return 1;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int K, L;
    cin >> N >> K;

    int x, y;
    for(int i=0; i<K; i++){
        cin >> x >> y;
        board[x - 1][y - 1] = 2;
    }

    cin >> L;
    char in;
    for(int i=0; i<L; i++){
        cin >> x >> in;
        rot.push(pair<int, char>(x, in));
    }

    snake.push(pair<int, int>(0,0));
    board[0][0] = 1;

    while(1){
        if(!move()) break;

        if(sec++ == rot.front().first){
            if(rot.front().second == 'L') head[2] = (head[2] + 3) % 4;
            else head[2] = (head[2] + 1) % 4;
            rot.pop();
        }
    }

    cout << sec;

    return 0;
}