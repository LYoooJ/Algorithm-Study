#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int H, W, X, Y;
    cin >> H >> W >> X >> Y;
    vector<vector<int>> v(H + X, vector<int>(W + Y, 0));
    
    for (int r = 0; r < H + X; r++) {
        for (int c = 0; c < W + Y; c++) {
            cin >> v[r][c];
        }
    } 

    for (int r = X; r < H; r++) {
        for (int c = Y; c < W; c++) {
            v[r][c] -= v[r - X][c - Y];
        }
    }

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            cout << v[r][c] << " ";
        }
        cout << "\n";
    }
    return 0;
}