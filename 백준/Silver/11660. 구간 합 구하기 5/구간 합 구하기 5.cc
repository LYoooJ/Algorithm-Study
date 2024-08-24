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

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> num;
            if (r == 0 && c == 0) {
                sum[r][c] = num;
            }
            else if (r == 0 && c != 0) {
                sum[r][c] = sum[r][c - 1] + num;
            }
            else if (r != 0 && c == 0) {
                sum[r][c] = sum[r - 1][c] + num;
            }
            else {
                sum[r][c] = sum[r - 1][c] + sum[r][c - 1] + num - sum[r - 1][c - 1];
            }
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        if (c1 == 1 && r1 == 1)
            result = sum[r2 - 1][c2 - 1];
        else if (c1 == 1 && r1 != 1)
            result = sum[r2 - 1][c2 - 1] - sum[r1 - 2][c2 - 1];
        else if (c1 != 1 && r1 == 1)
            result = sum[r2 - 1][c2 - 1] - sum[r2 - 1][c1 - 2];
        else
            result = sum[r2 - 1][c2 - 1] - sum[r1 - 2][c2 - 1] - sum[r2 - 1][c1 - 2] + sum[r1 - 2][c1 - 2];

        cout << result << "\n";
    }

    return 0;
}