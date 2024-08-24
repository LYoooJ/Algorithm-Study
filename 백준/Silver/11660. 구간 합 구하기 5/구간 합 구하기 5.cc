#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int r1, c1, r2, c2;
    int num, result;

    cin >> N >> M;

    vector<vector<int>> sum(N + 1, vector<int>(N + 1, 0));

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> num;
            sum[r][c] = sum[r - 1][c] + sum[r][c - 1] + num - sum[r - 1][c - 1];
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        result = sum[r2][c2] - sum[r1 - 1][c2] - sum[r2][c1 - 1] + sum[r1 - 1][c1 - 1];
        cout << result << "\n";
    }

    return 0;
}
