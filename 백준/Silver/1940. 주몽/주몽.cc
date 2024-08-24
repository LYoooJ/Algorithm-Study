#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, num;
    int start, end;
    int count = 0;

    cin >> N >> M;
    start = 0, end = N - 1;
    vector<int> m(N);

    for (int i = 0; i < N; i++) {
        cin >> m[i];
    }
    sort(m.begin(), m.end());

    while (start < end) {
        if (m[start] + m[end] < M) {
            start++;
        }
        else if (m[start] + m[end] > M) {
            end--;
        }
        else {
            start++;
            end--;
            count++;
        }
    }
    cout << count << "\n";

    return 0;
}