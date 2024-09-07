#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int H, W, sum = 0;
    cin >> H >> W;
    vector<int> h(W, 0);

    for (int i = 0; i < W; i++)
        cin >> h[i];

    for (int i = 1; i < W - 1; i++) {
        int left_max = 0, right_max = 0; 
        int min_h;

        //find maximum height in left
        for (int j = i - 1; j >= 0; j--) {
            left_max = left_max < h[j] ? h[j] : left_max;
        }

        //find maximum height in right
        for (int j = i + 1; j < W; j++) {
            right_max = right_max < h[j] ? h[j] : right_max;
        }
        min_h = left_max < right_max ? left_max : right_max;
        if (min_h > h[i])
            sum += min_h - h[i];
    }
    cout << sum << "\n";

    return 0;
}