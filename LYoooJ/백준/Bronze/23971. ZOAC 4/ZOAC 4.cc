#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int H, W, N, M;
    cin >> H >> W >> N >> M;

    int h_num = H % (N + 1) == 0 ? H / (N + 1) : H / (N + 1) + 1;
    int w_num = W % (M + 1) == 0 ? W / (M + 1) : W / (M + 1) + 1;
    cout << h_num * w_num;

    return 0;
}