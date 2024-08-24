#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void) {
    int N, M, num;
    long long result = 0;
    cin >> N >> M;

    vector<int> r(N + 1);
    map<int, int> m;

    for (int i = 0; i <= N; i++) {
        if (i == 0) {
            r[i] = 0;
        }
        else {
            cin >> num;
            r[i] = (r[i - 1] + num) % M;
        }
        m[r[i]] += 1;
    }

    for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second < 2)
            continue;
        else
            result += ((long long)iter->second * (iter->second - 1)) / 2;
    }
    cout << result << "\n";

    return 0;
}