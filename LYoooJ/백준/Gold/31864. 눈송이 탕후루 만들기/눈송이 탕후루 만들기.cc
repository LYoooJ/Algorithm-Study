#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int gcd(int a, int b);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, x, y, max = 0;
    cin >> N >> M;

    map<pair<int, int>, vector<pair<int, int>>> m;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        int gcd_xy = gcd(abs(x), abs(y));
        m[{x / gcd_xy, y / gcd_xy}].push_back(make_pair(abs(x), abs(y)));
    }

    for (map<pair<int, int>, vector<pair<int, int>>>::iterator iter = m.begin(); iter != m.end(); iter++)
        sort(iter->second.begin(), iter->second.end());

    for (int i = 0; i < M; i++) {
        int num = 0;
        cin >> x >> y;
        int gcd_xy = gcd(abs(x), abs(y));
        int gx = x / gcd_xy, gy = y / gcd_xy;
        if (m.count({gx, gy}) == 0)
            continue;
        num = (int)(upper_bound(m[{gx, gy}].begin(), m[{gx, gy}].end(), make_pair(abs(x), abs(y))) - m[{gx, gy}].begin());

        if (num > max)
            max = num;
    }

    cout << max;

    return 0;
}

int gcd(int a, int b) {
    int k;
    while (b != 0) {
        k = a % b;
        a = b;
        b = k;
    }
    return a;
}
