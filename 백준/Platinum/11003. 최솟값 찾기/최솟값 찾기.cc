#include <iostream>
#include <deque>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L, num;
    deque<pair<int, int>> dq;

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        cin >> num;
        if (dq.empty())
            dq.push_back(make_pair(i, num));
        else {
            while (!dq.empty() && num < dq.back().second)
                dq.pop_back();
            dq.push_back(make_pair(i, num));
        }
        if (dq.front().first < i - L + 1)
            dq.pop_front();
        
        cout << dq.front().second << " ";
    }
    cout << endl;

    return 0;
}