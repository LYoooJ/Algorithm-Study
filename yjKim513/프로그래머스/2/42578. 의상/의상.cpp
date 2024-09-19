#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> clothes_categorized;
    
    for (auto iter = clothes.begin(); iter != clothes.end(); iter++) {
        auto search = clothes_categorized.find((*iter)[1]);
        if (search == clothes_categorized.end())
            clothes_categorized.insert({(*iter)[1], 2});
        else
            (search->second)++;
    }
    
    int answer = 1;
    for (auto iter = clothes_categorized.begin(); iter != clothes_categorized.end(); iter++)
        answer *= iter->second;
    
    return --answer;
}