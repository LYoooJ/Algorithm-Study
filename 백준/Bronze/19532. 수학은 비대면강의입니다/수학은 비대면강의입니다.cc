#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d, e, f, x, y;
    bool flag = false;
    cin >> a >> b >> c >> d >> e >> f;

    for (x = -999; x < 1000; x++) {
        for (y = -999; y < 1000; y++) {
            if (a * x + b * y == c && d * x + e * y == f) {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }

    cout << x << " " << y << "\n";

    return 0;
}