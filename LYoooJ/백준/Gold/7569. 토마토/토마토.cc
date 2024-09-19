#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int r;
    int c;
    int h;
};

queue<Point> bfs(vector<vector<vector<int>>>& v, vector<vector<vector<int>>>& visited, queue<Point>& q);
bool is_valid(int r, int c, int h, int N, int M, int H);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, H, unripe_num = 0, day = 0;
    cin >> M >> N >> H;
    vector<vector<vector<int>>> v(N, vector<vector<int>>(M, vector<int>(H, 0)));
    vector<vector<vector<int>>> visited(N, vector<vector<int>>(M, vector<int>(H, 0)));
    queue<Point> q;

    for (int h = 0; h < H; h++) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                cin >> v[r][c][h];
                if (v[r][c][h] == 1) {
                    q.push({ r, c, h });
                }
                else if (v[r][c][h] == 0) {
                    unripe_num++;
                }
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
queue<Point> bfs(vector<vector<vector<int>>>& v, vector<vector<vector<int>>>& visited, queue<Point>& q) {
    static Point move[6] = { {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };
    queue<Point> new_q;

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int new_r = p.r + move[i].r;
            int new_c = p.c + move[i].c;
            int new_h = p.h + move[i].h;
            if (is_valid(new_r, new_c, new_h, v.size(), v[0].size(), v[0][0].size()) && !v[new_r][new_c][new_h] && !visited[new_r][new_c][new_h]) {
                v[new_r][new_c][new_h] = 1;
                new_q.push({ new_r, new_c, new_h });
            }
        }
    }
    return new_q;
}

bool is_valid(int r, int c, int h, int N, int M, int H) {
    return 0 <= r && r < N && 0 <= c && c < M && 0 <= h && h < H;
}
