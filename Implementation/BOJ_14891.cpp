#include <iostream>
#include <algorithm>

using namespace std;

int wheel[5][10];
bool visited[5];
int K;
pair<int, int> rotation[101];

void rotate(int idx, int dir){
    if (dir == -1){
        for (int i = 1; i <= 8; i++){
            wheel[idx][i - 1] = wheel[idx][i];
        }

        wheel[idx][8] = wheel[idx][0];
    }

    else if (dir == 1){
        for (int i = 8; i >= 1; i--){
            wheel[idx][i + 1] = wheel[idx][i];
        }

        wheel[idx][1] = wheel[idx][9];
    }
}

int main(){
    for (int i = 1; i <= 4; i++){
        for (int j = 1; j <= 8; j++){
            scanf("%1d", &wheel[i][j]);
        }
    }

    cin >> K;

    for (int i = 1; i <= K; i++){
        cin >> rotation[i].first >> rotation[i].second;
    }

    for (int i = 1; i <= K; i++){
        fill(visited, visited + 5, 0);
        visited[rotation[i].first] = true;
        for (int j = rotation[i].first; j <= 3; j++){
            if (wheel[j][3] != wheel[j + 1][7])     visited[j + 1] = true;
            else break;
        }

        for (int j = rotation[i].first; j >= 2; j--){
            if (wheel[j][7] != wheel[j - 1][3])     visited[j - 1] = true;
            else break;
        }

        for (int j = 1; j <= 4; j++){
            if (visited[j] == true){
                if (abs(rotation[i].first - j) % 2 == 1){
                    rotate(j, rotation[i].second * -1);
                }
                else if (abs(rotation[i].first - j) % 2 == 0){
                    rotate(j, rotation[i].second);
                }
            }
        }

        // for (int j = 1; j <= 4; j++){

        //     for (int i = 1; i <= 8; i++){
        //         cout << wheel[j][i] << ' ';
        //     }
        //     cout << endl;

        // }   
        
    }

    int res;

    res = wheel[1][1] + wheel[2][1] * 2 + wheel[3][1] * 4 + wheel[4][1] * 8;
    
    cout << res << '\n';

    return 0;
}