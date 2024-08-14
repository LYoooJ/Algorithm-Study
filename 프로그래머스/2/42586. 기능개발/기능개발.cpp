#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define complete 100

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for (int i = 0; i < progresses.size(); i++) {
        int days = (complete - progresses[i]) / speeds[i];
        if ((complete - progresses[i]) % speeds[i] == 0)
            q.push(days);
        else
            q.push(days + 1);
    }
        
    while (!q.empty()) {
        int front = q.front();
        int count = 0;
        while (!q.empty() && q.front() <= front) {
            q.pop();
            count++;
        }
        answer.push_back(count);
    }
    
    return answer;
}