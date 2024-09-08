#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int r;
    int c;
};

int bfs(vector<vector<int>>& v, vector<vector<int>>& visited, Point src);
void init_vistied(vector<vector<int>>& visited);
void init_v(vector<vector<int>>& v, vector<vector<int>>& original);
bool is_valid(int r, int c, int N, int M);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, max_area = 0, wall_area = 0;
    cin >> N >> M;
    vector<vector<int>> original(N, vector<int>(M, 0));
    vector<vector<int>> visited(N, vector<int>(M, 0));
    vector<vector<int>> v(N, vector<int>(M, 0));
    vector<Point> empty;
    vector<Point> virus;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> original[r][c];
            if (original[r][c] == 0) {
                empty.push_back({ r, c });
            }
            else if (original[r][c] == 2) {
                virus.push_back({ r, c });
            }
            else {
                wall_area++;
            }
        }
    }

    for (int i = 0; i < empty.size(); i++) {
        for (int j = 0; j < empty.size(); j++) {
            if (i == j)
                continue;
            for (int k = 0; k < empty.size(); k++) {
                if (i == k || j == k)
                    continue;
                init_v(v, original);
                init_vistied(visited);
                int virus_area = 0;
                v[empty[i].r][empty[i].c] = 1;
                v[empty[j].r][empty[j].c] = 1;
                v[empty[k].r][empty[k].c] = 1;
                
                if (empty[i].r == 2 && empty[i].c == 3 && empty[j].r == 1 && empty[j].c == 4 && empty[k].r == 0 && empty[k].c == 5)
                    int n = 0;
                for (vector<Point>::iterator iter = virus.begin(); iter != virus.end(); iter++) {
                    if (!visited[iter->r][iter->c]) {
                        virus_area += bfs(v, visited, { iter->r, iter->c });
                    }
                }
                int area = N * M - (wall_area + 3) - virus_area;
                max_area = area > max_area ? area : max_area;
            }
        }
    }
    cout << max_area << "\n";

    return 0;
}

int bfs(vector<vector<int>>& v, vector<vector<int>>& visited, Point src) {
    int virus_area = 1;
    static Point move[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    queue<Point> virus_q;

    virus_q.push({ src.r, src.c });
    visited[src.r][src.c] = 1;

    while (!virus_q.empty()) {
        Point p = virus_q.front();
        virus_q.pop();

        for (int i = 0; i < 4; i++) {
            int new_r = p.r + move[i].r;
            int new_c = p.c + move[i].c;
            if (is_valid(new_r, new_c, v.size(), v[0].size()) && v[new_r][new_c] != 1 && !visited[new_r][new_c]) {
                virus_q.push({ new_r, new_c });
                visited[new_r][new_c] = 1;
                virus_area++;
            }
        }
    }
    return virus_area;
}

void init_vistied(vector<vector<int>>& visited) {
    for (int r = 0; r < visited.size(); r++) {
        for (int c = 0; c < visited[r].size(); c++) {
            visited[r][c] = 0;
        }
    }
}

void init_v(vector<vector<int>>& v, vector<vector<int>>& original) {
    for (int r = 0; r < v.size(); r++) {
        for (int c = 0; c < v[r].size(); c++) {
            v[r][c] = original[r][c];
        }
    }
}

bool is_valid(int r, int c, int N, int M) {
    return 0 <= r && r < N && 0 <= c && c < M;
}
