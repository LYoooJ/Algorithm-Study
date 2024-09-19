#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    stack<int> stk;
    cin >> N;
    vector<int> v(N);
    vector<int> result(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < N; i++) {
        while (!stk.empty() && v[stk.top()] < v[i]) {
            int idx = stk.top();
            result[idx] = v[i];
            stk.pop();
        }
        stk.push(i); 
    }

    while (!stk.empty()) {
        int idx = stk.top();
        result[idx] = -1;
        stk.pop();
    }

    for (int i = 0; i < N; i++)
        cout << result[i] << " ";

    return 0;
}