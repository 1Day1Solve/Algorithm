#include <iostream>
using namespace std;

class Solution {
public:
    int dp[1000][1000];
    string longestPalindrome(string s) {
        int len = s.size();
        int m = 0, f, b;

        for(int i=len - 1; i>=0; i--){
            for(int j=i; j<len; j++){
                if(i == j) dp[i][j] = 1;
                else if(i == j-1 && s[i] == s[j]) dp[i][j] = 2;
                else if(s[i] == s[j] && dp[i+1][j-1]) dp[i][j] = dp[i+1][j-1] + 2;

                if(m < dp[i][j]) {
                    m = dp[i][j];
                    f = i;
                    b = j;
                }
            }   
        }
        
        return s.substr(f, b-f+1);
    }
};