#include <iostream>

#define W 20
#define H 20
#define move_type 4

using namespace std;

bool range_check(int r, int c) {
    return 1 <= r && r < H && 1 <= c && c < W;
}
bool check_win(int color, int (&A)[H][W], int r, int c) {
    pair<int, int> move[move_type] = { {1, 0}, {1, 1}, {0, 1}, {1, -1} };

    for (int i = 0; i < move_type; i++) {
        int num = 1;
        int pr = r - move[i].second, pc = c - move[i].first;
        if (range_check(pr, pc) && A[pr][pc] == color)
            continue;

        int r_ = r + move[i].second, c_ = c + move[i].first;

        while (r_ < H && c_ < H && A[r_][c_] == color) {
            num++;
            r_ += move[i].second;
            c_ += move[i].first;
        }
        if (num == 5)
            return true;
    }
    return false;
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A[H][W] = {0};
    bool flag = false;

    for (int r = 1; r < H; r++) {
        for (int c = 1; c < W; c++) {
            cin >> A[r][c];
        }
    }

    for (int c = 1; c < W; c++) {
        for (int r = 1; r < H; r++) {
            if (A[r][c] != 0 && check_win(A[r][c], A, r, c)) {
                cout << A[r][c] << "\n" << r << " " << c;
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    if (!flag)
        cout << 0 << "\n";

    return 0;
}
