#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int sum, vector<int>::iterator it, vector<int>::iterator end, vector<int>& sums);

int solution(vector<int> numbers, int target) {
    vector<int> sums;
    dfs(0, numbers.begin(), numbers.end(), sums);
    
    return count(sums.begin(), sums.end(), target);
}

void dfs(int sum, vector<int>::iterator it, vector<int>::iterator end, vector<int>& sums) {
    if (it == end) {
        sums.push_back(sum);
        return;
    }
    
    dfs(sum + *it, it + 1, end, sums);
    dfs(sum - *it, it + 1, end, sums);
}