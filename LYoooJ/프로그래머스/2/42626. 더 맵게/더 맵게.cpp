#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq (scoville.begin(), scoville.end());
    int count = 0;
    
    while (pq.size() > 1 && pq.top() < K) {
        int old1 = pq.top();
        pq.pop();
        int old2 = pq.top();
        pq.pop();
        pq.push(old1 + 2 * old2);
        count++;
    }
    return pq.top() >= K ? count : -1;
}