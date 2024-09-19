#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    bool kind[200001] = {0, };
    
    for (int i = 1; i < nums.size(); i++) {
        if (!kind[nums[i]]) {
            kind[nums[i]] = 1;
            answer++;
            if (answer >= nums.size() / 2)
                return answer;
        }
    }
    
    return answer;
}