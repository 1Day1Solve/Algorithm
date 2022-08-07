#include <iostream>
using namespace std;

int dice[6] = { 0, };           //윗면, 위쪽 옆면, 오른쪽 옆면, 아래쪽 옆면, 왼쪽 옆면, 아랫면
int map[20][20];
int N, M, x, y;

void move(int input){
    if((input == 1 && y == M - 1)
    || (input == 2 && y == 0)
    || (input == 3 && x == 0)
    || (input == 4 && x == N - 1))
        return;

    int temp = dice[0];
    switch(input){
        case 1:
        y++;
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[2];
        dice[2] = temp;
        break;
        case 2:
        y--;
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[4];
        dice[4] = temp;
        break;
        case 3:
        x--;
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[1];
        dice[1] = temp;
        break;
        case 4:
        x++;
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[3];
        dice[3] = temp;
        break;
    }

    if(map[x][y]){
        dice[5] = map[x][y];
        map[x][y] = 0;
    }
    else map[x][y] = dice[5];

    cout << dice[0] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int K;

    cin >> N >> M >> x >> y >> K;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }

    int input;

    for(int i=0; i<K; i++){
        cin >> input;
        move(input);
    }

    return 0;
}