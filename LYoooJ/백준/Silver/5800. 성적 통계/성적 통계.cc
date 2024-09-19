#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    
    cin >> K;

    for (int i = 1; i <= K; i++) {
        int N;
        int gap_max = 0;
        cin >> N;
        vector<int> v(N);

        for (int j = 0; j < N; j++) {
            cin >> v[j];
        }

        sort(v.begin(), v.end());

        for (int j = 0; j < N - 1; j++) {
            gap_max = gap_max < abs(v[j] - v[j + 1]) ? abs(v[j] - v[j + 1]) : gap_max;
        }

        cout << "Class " << i << "\n";
        cout << "Max " << *(--v.end()) << ", Min " << *v.begin() << ", Largest gap " << gap_max << "\n";
    }
    return 0;
}