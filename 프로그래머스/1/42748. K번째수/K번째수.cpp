#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int>::iterator array_begin = array.begin();
    
    for (vector<vector<int>>::iterator iter = commands.begin(); iter != commands.end(); iter++) {
        vector<int> slice(array_begin + (*iter)[0] - 1, array_begin + (*iter)[1]);
        sort(slice.begin(), slice.end());
        answer.push_back(slice[(*iter)[2] - 1]);
    }
    return answer;
}