#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int graph[101][101];
int N, cnt;

int main(){
    deque<pair<int, int> > body;
    deque<pair<int, char> > turn;
    vector<pair<int, int> > apples;

    cin >> N >> cnt;

    for (int i = 0; i < cnt; i++){
        int x, y;
        cin >> x >> y;

        apples.push_back(make_pair(x, y));
    }

    cin >> cnt;

    for (int i = 0; i < cnt; i++){
        int x;
        char y;
        cin >> x >> y;

        turn.push_back(make_pair(x, y));
    }

    body.push_back(make_pair(1, 1));

    int time = 0, dir = 0;
    int curX = 1, curY = 1;
    while (1){
        // 시간 증가
        time++;

        // 방향 결정
        if (turn.front().first == time - 1) {
            if (turn.front().second == 'L')         dir = (dir + 3) % 4;
            else if (turn.front().second == 'D')    dir = (dir + 1) % 4;

            turn.pop_front();
        }
        
        // 움직이기
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];

        // 벽에 부딪혔을 때
        if (nx > N || ny > N || nx <= 0 || ny <= 0)   break; 

        bool flag = false;
        // 자기 몸이랑 부딪혔을 때
        for (const auto& i: body) {
            if (i.first == nx && i.second == ny)    {flag = true;   break;}
        }
        
        if (flag)   break;

        // 몸 queue에다가 push
        body.push_back(make_pair(nx, ny));

        int tempX = -1, tempY = -1;
        // 사과를 먹었을 때
        for (const auto& i: apples) {
            if (i.first == nx && i.second == ny)    {
                flag = true;   
                tempX = i.first;
                tempY = i.second;

                break;
            }
        }
        
        for (auto it = apples.begin(); it != apples.end(); it++){
            if (it -> first == tempX && it -> second == tempY)  {apples.erase(it); break;}
        }

        // 안 먹었으면 pop
        if (!flag)   body.pop_front();

        // 위치 이동
        curX = nx;
        curY = ny;

        // cout << time << ' ' << curX << ' ' << curY << endl;

    }
    
    cout << time << '\n';

    return 0;
}