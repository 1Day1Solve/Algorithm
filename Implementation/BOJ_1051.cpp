#include <iostream>
#include <vector>

using namespace std;

int graph[51][51];
int N, M;

int main(){

    cin >> N >> M;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            scanf("%1d", &graph[i][j]);
        }
    }

    // for (int i = 1; i <= N; i++){
    //     for (int j = 1; j <= M; j++){
    //         cout << graph[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // 최대 50 * 50 * 10개 검사니까 무지성 브루트포스해도 25000개

    int max_area = 1;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            for (int k = 1; k < min(N, M); k++){
                int startV = graph[i][j];
                int area = -1;
                
                // 밖으로 나가는 경우
                if (i + k > N || j + k > M)     continue;
                // 꼭짓점끼리 다 같은 경우
                if (graph[i][j + k] == startV &&
                    graph[i + k][j] == startV &&
                    graph[i + k][j + k] == startV){
    
                    area = (k + 1) * (k + 1);
                }

                if (max_area < area)    max_area = area;
                
            }
        }
    }
    
    cout << max_area << endl;

    return 0;
}