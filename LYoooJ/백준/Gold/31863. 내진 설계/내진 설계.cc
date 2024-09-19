#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int r;
    int c;
    int dist;
    Point(int r, int c, int dist) {
        this->r = r;
        this->c = c;
        this->dist = dist;
    }
};

int init_map(vector<vector<int>>& v, queue<Point>& q, int N);
int simulate(vector<vector<int>>& v, queue<Point>& q);
bool is_valid_range(int N, int M, int r, int c);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int total_num, broken_num;
    cin >> N >> M;

    vector<vector<int>> v(N, vector<int> (M, 0));
    queue<Point> q;

    total_num = init_map(v, q, N);
    broken_num = simulate(v, q);

    cout << broken_num << " " << total_num - broken_num << "\n";

    return 0;
}

/* Return the number of buildings */
int init_map(vector<vector<int>>& v, queue<Point>& q, int N) {
    int num = 0;

    for (int r = 0; r < N; r++) {
        string str;
        cin >> str;
        for (int c = 0; c < str.size(); c++) {
            switch (str[c])
            {
            case '@':
                q.push(Point(r, c, 2));
                break;
            case '.':
                break;
            case '*':
                v[r][c] = 1;
                num++;
                break;
            case '#':
                v[r][c] = 2;
                num++;
                break;
            case '|':
                v[r][c] = -1;
                break;
            }
        }
    }
    return num;
}

int simulate(vector<vector<int>>& v, queue<Point>& q) {
    int broken_num = 0;
    pair<int, int> move[4] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };

    while (!q.empty()) {
        Point src = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = src.r, c = src.c;
            int dr = move[i].first;
            int dc = move[i].second;
            for (int j = 0; j < src.dist; j++) {
                r += dr;
                c += dc;
                if (!is_valid_range(v.size(), v[0].size(), r, c))
                    break;

                if (v[r][c] == -1)
                    break;
                else if (v[r][c] > 0 && --v[r][c] == 0) {
                    broken_num += 1;
                    q.push(Point(r, c, 1));
                }
            }
        }
    }
    return broken_num;
}

bool is_valid_range(int N, int M, int r, int c) {
    return 0 <= r && r < N && 0 <= c && c < M;
}