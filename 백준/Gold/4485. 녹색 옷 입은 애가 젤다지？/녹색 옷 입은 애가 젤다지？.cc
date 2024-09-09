#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

struct Point {
    int r;
    int c;
    int cost;
};

struct cmp {
    bool operator () (Point a, Point b) {
        if (a.cost > b.cost)
            return true;
        else
            return false;
    }
};

int dijkstra(vector<vector<int>>& v, vector<vector<int>>& cost, vector<vector<int>>& visited, Point src);
bool is_valid(int r, int c, int N);


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num = 1;

    while (true) {
        cin >> N;
        if (N == 0)
            break;

        vector<vector<int>> v(N, vector<int>(N, 0));
        vector<vector<int>> cost(N, vector<int>(N, INF));
        vector<vector<int>> visited(N, vector<int>(N, 0));

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                cin >> v[r][c];
            }
        }

        cout << "Problem " << num++ << ": " << dijkstra(v, cost, visited, {0, 0, v[0][0]}) << "\n";
    }

    return 0;
}

int dijkstra(vector<vector<int>>& v, vector<vector<int>>& cost, vector<vector<int>>& visited, Point src) {
    static Point move[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    priority_queue<Point, vector<Point>, cmp> pq;
    pq.push(src);
    cost[src.r][src.c] = v[src.r][src.c];

    while (!pq.empty()) {
        Point p = pq.top();
        pq.pop();
        if (visited[p.r][p.c])
            continue;

        visited[p.r][p.c] = 1;
        for (int i = 0; i < 4; i++) {
            int new_r = p.r + move[i].r;
            int new_c = p.c + move[i].c;
            if (is_valid(new_r, new_c, v.size()) && !visited[new_r][new_c]) {
                int new_cost = cost[p.r][p.c] + v[new_r][new_c];
                if (new_cost < cost[new_r][new_c]) {
                    pq.push({ new_r, new_c, new_cost });
                    cost[new_r][new_c] = new_cost;
                }
            }
        }
    }
    return cost[v.size() - 1][v.size() - 1];
}

bool is_valid(int r, int c, int N) {
    return 0 <= r && r < N && 0 <= c && c < N;
}