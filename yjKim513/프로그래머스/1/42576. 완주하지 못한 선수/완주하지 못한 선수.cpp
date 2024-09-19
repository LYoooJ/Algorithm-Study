#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> players;
    
    for (auto iter = participant.begin(); iter != participant.end(); iter++) {
        if (players.find(*iter) == players.end()) {
            players.insert({*iter, 1});
        }
        else {
            (players.find(*iter)->second)++;
        }
    }
    
    for (auto iter = completion.begin(); iter != completion.end(); iter++) {
        if (--(players.find(*iter)->second) == 0)
            players.erase(*iter);
    }
    
    return players.begin()->first;
}