#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    cin >> N;
    vector<int> v(10001, 0);

    for (int i = 0; i < N; i++) {
        cin >> num;
        v[num]++;
    }

    for (int i = 1; i < 10001; i++) {
        for (int j = 0; j < v[i]; j++) {
            cout << i << "\n";
        }
    }

    return 0;
}