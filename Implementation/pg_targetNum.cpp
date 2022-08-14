#include <string>
#include <vector>

using namespace std;

int answer = 0, tar, len;
vector<int> gNum;

void dfs(int cnt, int result)
{
    if (cnt == len - 1)
    {
        if (result + gNum[cnt] == tar)
            answer++;
        if (result - gNum[cnt] == tar)
            answer++;
        return;
    }

    dfs(cnt + 1, result + gNum[cnt]);
    dfs(cnt + 1, result - gNum[cnt]);
}

int solution(vector<int> numbers, int target)
{
    gNum = vector<int>(numbers);
    len = gNum.size();
    tar = target;
    dfs(0, 0);
    return answer;
}