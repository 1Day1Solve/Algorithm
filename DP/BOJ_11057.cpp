#include <iostream>

using namespace std;

int N;
long long d[1001][10];

int main(){
    cin >> N;

    for (int i = 0; i < 10; i++){
        d[1][i] = 1;
    }

    /*  d[2][0] = 1 (00)
        d[2][1] = 2 (01, 11)
        d[2][2] = 3 (02, 12, 22)

        .
        .
        .

        d[3][0] = 1 (000)
        d[3][1] = 3 (001, 011, 111)
        d[3][2] = 6 (002, 012, 022, 112, 122, 222)

        .
        .
        .

        d[4][0] = 1 (0000)
        d[4][1] = 4 (0001, 0011, 0111, 1111)
        d[4][2] = 10 (d[3][2] + d[4][1])
     */

    for (int i = 2; i <= N; i++){
        for (int j = 0; j < 10; j++){
            if (j == 0)     {d[i][j] = 1;   continue;}
            d[i][j] = (d[i - 1][j] + d[i][j - 1]) % 10007;
        }
    }

    long long res = 0;
    for (int i = 0; i < 10; i++){
        res += d[N][i];
    }
    res %= 10007;

    cout << res << '\n';


    return 0;
}