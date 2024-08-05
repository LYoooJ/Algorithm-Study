#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    
    for (vector<string>::iterator iter = participant.begin(); iter != participant.end(); iter++) 
            m[*iter] += 1;
    
    for (vector<string>::iterator iter = completion.begin(); iter != completion.end(); iter++) {
        if (m[*iter] == 1)
            m.erase(*iter);
        else
            m[*iter] -= 1;
    }
    
    return m.begin()->first;
}