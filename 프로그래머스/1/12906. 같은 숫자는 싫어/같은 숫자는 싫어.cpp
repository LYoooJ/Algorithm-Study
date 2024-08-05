#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    for(vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++) {
        if (answer.empty() || answer.back() != *iter) 
            answer.push_back(*iter);
    }

    return answer;
}