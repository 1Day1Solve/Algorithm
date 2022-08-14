#include <iostream>
#include <vector>
using namespace std;

int gear[5][8];
bool checked[5] = {false};

void rotate(int dir, int num){
    checked[num] = true;
    if(num != 4 && gear[num][2] != gear[num+1][6] && !checked[num+1]){
        rotate(dir * -1, num+1);
    }
    if(num != 1 && gear[num][6] != gear[num-1][2] && !checked[num-1]){
        rotate(dir * -1, num-1);
    }

    int temp;
    if(dir == 1) 
    {
        temp = gear[num][7];
        for(int i=7; i>0; i--){
            gear[num][i] = gear[num][i-1];
        }
        gear[num][0] = temp;
    }
    else 
    {
        temp = gear[num][0];
        for(int i=0; i<7; i++){
            gear[num][i] = gear[num][i+1];
        }
        gear[num][7] = temp;
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int K, gNum, gDir;
    string input;

    //입력
    for(int i = 1; i <= 4; i++){
        cin >> input;
        for(int j = 0; j < 8; j++){
            gear[i][j] = input[j] - '0';
        }
    }

    //회전
    cin >> K;
    for(int i=0; i<K; i++){
        cin >> gNum >> gDir;
        rotate(gDir, gNum);
        for(int j = 1; j < 5; j++){
            checked[j] = false;
        }
    }
    
    //점수계산
    int score = 1, total = 0;
    for(int i=1; i<=4; i++){
        if(gear[i][0]) total += score;
        score *= 2;
    }

    cout << total;

    return 0;
}