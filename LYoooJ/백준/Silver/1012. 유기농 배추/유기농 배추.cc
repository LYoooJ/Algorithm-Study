#include <iostream>
#include <vector>

using namespace std;

struct Position {
    int r;
    int c;
};

void dfs(vector<vector<int>>& v, vector<vector<int>>& visited, Position src);
bool is_valid(int r, int c, int N, int M);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T ,M, N, K;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> M >> N >> K;
        vector<vector<int>> v(N, vector<int>(M, 0));
        vector<vector<int>> visited(N, vector<int>(M, 0));
        int min_num = 0;

        for (int j = 0; j < K; j++) {
            int r_, c_;
            cin >> c_ >> r_;
            v[r_][c_] = 1;
        }

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (v[r][c] && !visited[r][c]) {
                    dfs(v, visited, { r, c });
                    min_num++;
                }
            }
        }
        cout << min_num << "\n";
    }
    return 0;
}

void dfs(vector<vector<int>>& v, vector<vector<int>>& visited, Position src) {
    static Position move[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    visited[src.r][src.c] = 1;
    for (int i = 0; i < 4; i++) {
        int new_r = src.r + move[i].r;
        int new_c = src.c + move[i].c;
        if (is_valid(new_r, new_c, v.size(), v[src.r].size()) && v[new_r][new_c] && !visited[new_r][new_c]) {
            dfs(v, visited, { new_r, new_c });
        }
    }
}

bool is_valid(int r, int c, int N, int M) {
    return 0 <= r && r < N && 0 <= c && c < M;
}
