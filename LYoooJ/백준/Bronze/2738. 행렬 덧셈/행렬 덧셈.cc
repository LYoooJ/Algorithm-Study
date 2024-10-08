#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, num;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> A[r][c];
        }
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> num;
            cout << A[r][c] + num << " ";
        }
        cout << "\n";
    }
    return 0;
}