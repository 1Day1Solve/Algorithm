#include <iostream>
#include <algorithm>

using namespace std;

int N, L;
int graph[101][101];

int main(){

    cin >> N >> L;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cin >> graph[i][j];
        }
    }


    int res = N * 2;
    for (int i = 1; i <= N; i++){
        int cnt = 0;
        for (int j = 1; j < N; j++){
            cnt++;
            
            // 같을 때
            if (graph[i][j] == graph[i][j + 1])     {continue;}

            // 내려가야할 때
            else if (graph[i][j] == graph[i][j + 1] + 1){
                bool flag = true;

                // 밖으로 삐져 나올 때
                if (j + L > N)      {res--; break;}

                // 다음 것이 그래프 안쪽인데 높이가 경사로 높이랑 다를 때
                // if (j + L + 1 <= N && graph[i][j + L] != graph[i][j + L + 1]) {cout << i << " case2" << endl;res--; break;}

                // 길이 이어져 있는지 검사
                for (int k = j + 1; k < j + L; k++){
                    if (graph[i][k] != graph[i][k + 1])     flag = false;
                }

                if (!flag)  {res--; break;}

                // 카운트 초기화 후 경사로 다음꺼로 이동
                cnt = -1;
                j = j + L - 1;
                continue;
            }

            // 올라가야할 때
            else if (graph[i][j] == graph[i][j + 1] - 1){
                if (cnt < L)    {res--; break;}
                cnt = 0;
            }

            // 높이 차이가 1이 아닐 때
            else    {res--; break;}
        }
        
    }

    for (int i = 1; i <= N; i++){
        for (int j = i; j <= N; j++){
            swap(graph[i][j], graph[j][i]);
        }
    }
    // cout << "swaped" << endl;

    for (int i = 1; i <= N; i++){
        int cnt = 0;
        for (int j = 1; j < N; j++){
            cnt++;
            
            // 같을 때
            if (graph[i][j] == graph[i][j + 1])     {continue;}

            // 내려가야할 때
            else if (graph[i][j] == graph[i][j + 1] + 1){
                bool flag = true;

                // 밖으로 삐져 나올 때
                if (j + L > N)      {res--; break;}

                // 다음 것이 그래프 안쪽인데 높이가 경사로 높이랑 다를 때
                // if (j + L + 1 <= N && graph[i][j + L] != graph[i][j + L + 1]) {cout << i << " case2" << endl;res--; break;}

                // 길이 이어져 있는지 검사
                for (int k = j + 1; k < j + L; k++){
                    if (graph[i][k] != graph[i][k + 1])     flag = false;
                }

                if (!flag)  {res--; break;}

                // 카운트 초기화 후 경사로 다음꺼로 이동
                cnt = -1;
                j = j + L - 1;
                continue;
            }

            // 올라가야할 때
            else if (graph[i][j] == graph[i][j + 1] - 1){
                if (cnt < L)    {res--; break;}
                cnt = 0;
            }

            // 높이 차이가 1이 아닐 때
            else    {res--; break;}
        }
        
    }


    cout << res << '\n';

}