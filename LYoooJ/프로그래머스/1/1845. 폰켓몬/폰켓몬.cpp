#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    set<int> types;
    for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
        types.insert(*iter);
    return min(nums.size()/2, types.size());
}