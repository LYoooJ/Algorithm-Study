#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int r;
    int c;
};

queue<Point> bfs(vector<vector<int>>& v, vector<vector<int>>& visited, queue<Point>& q);
bool is_valid(int r, int c, int N, int M);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, unripe_num = 0, day = 0;
    cin >> M >> N;
    vector<vector<int>> v(N, vector<int>(M, 0));
    vector<vector<int>> visited(N, vector<int>(M, 0));
    queue<Point> q;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> v[r][c];
            if (v[r][c] == 1) {
                q.push({ r, c });
            }
            else if (v[r][c] == 0) {
                unripe_num++;
            }
        }
    }

    while (unripe_num > 0 && !q.empty()) {
        q = bfs(v, visited, q);
        unripe_num -= q.size();
        day++;
    }

    if (unripe_num > 0) {
        cout << -1 << "\n";
    }
    else {
        cout << day << "\n";
    }

    return 0;
}

/* Return the queue of the tomatoes that become ripe newly */
queue<Point> bfs(vector<vector<int>>& v, vector<vector<int>>& visited, queue<Point>& q) {
    static Point move[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    queue<Point> new_q;

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_r = p.r + move[i].r;
            int new_c = p.c + move[i].c;
            if (is_valid(new_r, new_c, v.size(), v[0].size()) && !v[new_r][new_c] && !visited[new_r][new_c]) {
                v[new_r][new_c] = 2;
                new_q.push({ new_r, new_c });
            }
        }
    }
    return new_q;
}

bool is_valid(int r, int c, int N, int M) {
    return 0 <= r && r < N && 0 <= c && c < M;
}
