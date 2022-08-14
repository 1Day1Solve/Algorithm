#include <iostream>
using namespace std;

int dp[10] ={1,1,1,1,1,1,1,1,1,1};

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int N, num;
    cin >> N;

    for(int i=1; i<N; i++){
        for(int j=0; j<10; j++){
            num = 0;
            for(int k=j; k<10; k++){
                num += dp[k];
            }
            dp[j] = num % 10007;
        }
    }

    int total = 0;
    for(int i : dp) total += i;
    cout << total % 10007;

    return 0;
}