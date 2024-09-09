#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;
    vector<int> v(N + 1, 0);

    v[0] = 1;
    v[1] = 1;
    for (int i = 2; i < N; i++) {
        for (int j = 2 * i; j <= N; j += i) {
            v[j] = 1;
        }
    }

    for (int i = M; i <= N; i++) {
        if (v[i] == 0)
            cout << i << "\n";
    }
    
    return 0;
}