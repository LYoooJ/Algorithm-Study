#include <iostream>
#include <vector>

using namespace std;

int rotate_dir(int cur_dir);
int simulate(int cur_r, int cur_c, int cur_dir, vector<vector<int>>& v);
bool empty_dirty_loc_exist(int r, int c, vector<vector<int>>& v);
bool is_valid(int r, int c, int N, int M);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    int cur_r, cur_c, d;
    cin >> N >> M;
    cin >> cur_r >> cur_c >> d;
    vector<vector<int>> v(N, vector<int>(M, 0));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> v[r][c];
        }
    }
    cout << simulate(cur_r, cur_c, d, v);

    return 0;
}

int rotate_dir(int cur_dir) {
    if (cur_dir == 0)
        return 3;
    else
        return cur_dir - 1;
}

int simulate(int cur_r, int cur_c, int cur_dir, vector<vector<int>>& v) {
    pair<int, int> back_move[4] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
    pair<int, int> front_move[4] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

    int area = 0;
    int r = cur_r, c = cur_c;
    int dir = cur_dir;
    while (true) {
        if (v[r][c] == 0) { 
            v[r][c] = -1;
            area++;
        }

        if (!empty_dirty_loc_exist(r, c, v)) {
            int r_ = r + back_move[dir].second;
            int c_ = c + back_move[dir].first;

            if (is_valid(r_, c_, v.size(), v[0].size())) {
                if (v[r_][c_] == 1) {
                    break;
                }
                else {
                    r = r_;
                    c = c_;
                }
            }
        }
        else {
            for (int i = 0; i < 4; i++) {
                dir = rotate_dir(dir);
                int r_ = r + front_move[dir].second;
                int c_ = c + front_move[dir].first;
                if (v[r_][c_] == 0) {
                    r = r_;
                    c = c_;
                    break;
                }
            }
        }
    }
    return area;
}

bool empty_dirty_loc_exist(int r, int c, vector<vector<int>>& v) {
    pair<int, int> move[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    for (int i = 0; i < 4; i++) {
        int r_ = r + move[i].second;
        int c_ = c + move[i].first;

        if (is_valid(r_, c_, v.size(), v[0].size()) && v[r_][c_] == 0)
            return true;
    }
    return false;
}

bool is_valid(int r, int c, int N, int M) {
    return 0 <= r && r < N && 0 <= c && c < M;
}
