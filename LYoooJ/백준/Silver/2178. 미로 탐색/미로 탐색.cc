#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Point {
    int r;
    int c;
    int dist;
};

int bfs(vector<vector<int>>& v, vector<vector<int>> visited, pair<int, int> tgt);
bool is_valid(int r, int c, int N, int M);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M, 0));
    vector<vector<int>> visited(N, vector<int>(M, 0));
    string map;

    for (int r = 0; r < N; r++) {
        cin >> map;
        for (int c = 0; c < M; c++) {
            v[r][c] = map[c] - '0';
        }
    }

    cout << bfs(v, visited, make_pair(M, N)) << "\n";

    return 0;
}

int bfs(vector<vector<int>>& v, vector<vector<int>> visited, pair<int, int> tgt) {
    pair<int, int> move[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

    bool flag = false;

    queue<Point> q;
    q.push({0, 0, 1});

    while (!q.empty()) {
        Point cur = q.front();
        int r = cur.r;
        int c = cur.c;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r_ = r + move[i].second;
            int c_ = c + move[i].first;

            if (is_valid(r_, c_, v.size(), v[0].size()) && v[r_][c_] && !visited[r_][c_]) {
                q.push({r_, c_, cur.dist + 1});
                visited[r_][c_] = 1;
            }
            if (r_ == tgt.second - 1 && c_ == tgt.first - 1) {
                return cur.dist + 1;
            }
        }
    }

    return -1;
}

bool is_valid(int r, int c, int N, int M) {
    return 0 <= r && r < N && 0 <= c && c < M;
}