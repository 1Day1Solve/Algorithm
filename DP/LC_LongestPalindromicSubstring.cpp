#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
    bool d[1001][1001];
    
    string longestPalindrome(string s) {
        string answer = "";
        
        memset(d, false, sizeof(d));
        
        if (s.empty())      return answer;
        
        for (int i = 0; i < s.length(); i++){
            d[i][i] = true;
            if (answer.empty())   answer = s.substr(i, 1);
        }
        
        for (int i = 0; i < s.length() - 1; i++){
            if (s[i] == s[i + 1])   {
                d[i][i + 1] = true;
                if (answer.length() < 2)    answer = s.substr(i, 2);
            }
        }
        
        
        for (int i = 2; i < s.size(); i++){
            for (int j = 0; j + i < s.size(); j++){
                if (s[j] == s[j + i] && d[j + 1][j + i - 1]){
                    d[j][j + i] = true;
                    if (answer.length() < i + 1){
                        answer = s.substr(j, i + 1);
                    }
                }
            }
        }
        
        return answer;        
    }
    
};