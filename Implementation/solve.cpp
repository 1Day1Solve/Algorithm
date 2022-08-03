#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int N, M, idx, h, m = 1;
    cin >> N >> M;
    string a;

    int** rec = new int* [N];
    for(int i=0;i<N;i++) rec[i] = new int[M];

    for(int i=0;i<N;i++) {
        cin >> a;
        for(int j=0;j<M;j++) rec[i][j] = a[j] - '0';
    }

    for(int i=0;i<N;i++) for(int j=0;j<M;j++){
        idx = j + 1;
        while(idx < M) {
            if(rec[i][idx] == rec[i][j]){
                h = idx - j;
                if(i+h < N && rec[i+h][j] == rec[i][j] && rec[i+h][idx] == rec[i][j]) m = (m > (h+1) * (h+1))? m : (h+1) * (h+1);
            }
            idx++;
        }
    }

    cout << m;

    return 0;
}