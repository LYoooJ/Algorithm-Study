#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search_(vector<int>& v, int target);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, target;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> target;
        if (binary_search_(v, target))
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
    return 0;
}

bool binary_search_(vector<int>& v, int target) {
    int left = 0, right = v.size() - 1;
    while (left <= right) {
        if (left == right)
            return v[left] == target;

        int M = (left + right) / 2;
        if (v[M] > target)
            right = M - 1;
        else if (v[M] < target)
            left = M + 1;
        else
            return true;
    }
    return false;
}