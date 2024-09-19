#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Position {
    int r;
    int c;
};

int bfs(vector<vector<int>>& v, vector<vector<int>>& visited, Position src);
bool is_valid(int r, int c, int N, int M);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, max = 0, num = 0;
    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M, 0));
    vector<vector<int>> visited(N, vector<int>(M, 0));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> v[r][c];
        }
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (v[r][c] && !visited[r][c]) {
                visited[r][c] = 1;
                int area = bfs(v, visited, {r, c});
                max = max < area ? area : max;
                num++;
            }
        }
    }
    cout << num << "\n" << max << "\n";

    return 0;
}

int bfs(vector<vector<int>>& v, vector<vector<int>>& visited, Position src) {
    queue<Position> q;
    Position move[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    int area = 1;
    q.push(src);
    while (!q.empty()) {
        Position p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_r = p.r + move[i].r;
            int next_c = p.c + move[i].c;
            if (is_valid(next_r, next_c, v.size(), v[0].size()) && v[next_r][next_c] && !visited[next_r][next_c]) {
                q.push({ next_r, next_c });
                visited[next_r][next_c] = 1;
                area++;
            }
        }
    }
    return area;
}

bool is_valid(int r, int c, int N, int M) {
    return 0 <= r && r < N && 0 <= c && c < M;
}