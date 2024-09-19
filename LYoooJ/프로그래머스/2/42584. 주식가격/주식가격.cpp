#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<pair<int, int>> prices_stack; // stack of <index, price> pair
    int last_index = prices.size() - 1;

    for (int cur = 0; cur < prices.size(); cur++) {
        while (!prices_stack.empty() && prices_stack.top().second > prices[cur]) {
            int time = prices_stack.top().first;
            prices_stack.pop();
            answer[time] = cur - time; // calculate time difference
        }
        prices_stack.push(make_pair(cur, prices[cur]));
    }
    
    while (!prices_stack.empty()) {
        pair<int, int> p = prices_stack.top();
        prices_stack.pop();
        answer[p.first] = last_index - p.first;
    }
    
    return answer;
}