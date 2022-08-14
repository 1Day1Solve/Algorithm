// #include <string>
// #include <vector>

// using namespace std;

// void dfs(const vector<int> &numbers, int &answer, int target, int cnt, int sum){
//     if (cnt == numbers.size() - 1) {
//         if (target == sum + numbers[cnt]){     
//             answer++;
//         }
//         if (target == sum - numbers[cnt]){      
//             answer++;
//         }
//         return;
//     }
//     dfs(numbers, answer, target, cnt + 1, sum + numbers[cnt]);
//     dfs(numbers, answer, target, cnt + 1, sum - numbers[cnt]);
// }

// int solution(vector<int> numbers, int target) {
//     int answer = 0;
//     dfs(numbers, answer, target, 0, 0);
    
//     return answer;
// }


#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer = 0;

void bfs(const vector<int> &numbers, int target){
    queue<pair<int, int>> q;
    
    q.push(make_pair(numbers[0], 0));
    
    while (!q.empty()){
        int val = q.front().first;
        int depth = q.front().second;
        
        q.pop();

        if (val == target && depth == numbers.size() - 1)       answer++;
        if (depth > numbers.size())             return;
        
        q.push(make_pair(val - numbers[depth + 1], depth + 1));
        q.push(make_pair(val + numbers[depth + 1], depth + 1));
    }
    
}

int solution(vector<int> numbers, int target) {
    
    bfs(numbers, target);
    numbers[0] *= -1;
    bfs(numbers, target);
    
    return answer;
}