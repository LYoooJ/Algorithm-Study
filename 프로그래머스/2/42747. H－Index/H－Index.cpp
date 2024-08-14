#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int idx;
    int total_num = citations.size();
    sort(citations.begin(), citations.end());
    
    for (idx = total_num; idx >= 0; idx--) {
        if (citations[total_num - idx] >= idx)
            break;
    }
    
    return idx;
}