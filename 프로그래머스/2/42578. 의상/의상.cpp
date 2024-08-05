#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    int types = 1;
    
    for (vector<vector<string>>::iterator iter = clothes.begin(); iter != clothes.end(); iter++) 
        m[(*iter)[1]] += 1;    
    
    for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++) 
        types *= (iter->second + 1);
    
    return types - 1;
}