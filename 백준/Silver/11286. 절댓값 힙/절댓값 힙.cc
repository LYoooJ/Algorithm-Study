#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct compare {
    bool operator()(int n1, int n2) {
        int abs_n1 = n1 < 0 ? -n1 : n1;
        int abs_n2 = n2 < 0 ? -n2 : n2;

        if (abs_n1 > abs_n2)
            return true;
        else if (abs_n1 < abs_n2)
            return false;

        return n1 > n2;
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num, top;
    priority_queue<int, vector<int>, compare> pq;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num == 0) {
            if (pq.empty()) {
                top = 0;
            }
            else {
                top = pq.top();
                pq.pop();
            }
            cout << top << " ";
        }
        else {
            pq.push(num);
        }
    }

    return 0;
}
