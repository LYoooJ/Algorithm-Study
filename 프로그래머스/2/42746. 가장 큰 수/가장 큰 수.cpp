#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* if s1 is greater than s2 return true, or return false */
bool string_cmp(string s1, string s2) {
    return s1 + s2 > s2 + s1;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++) 
        v.push_back(to_string(*iter));
    
    sort(v.begin(), v.end(), string_cmp);
    
    for (vector<string>::iterator iter = v.begin(); iter != v.end(); iter++) {
        if (answer != "0")
            answer += *iter;
    }
      
    return answer;
}