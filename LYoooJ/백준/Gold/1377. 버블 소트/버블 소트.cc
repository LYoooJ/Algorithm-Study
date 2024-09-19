#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool less_cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second)
        return true;
    else if (p1.second > p2.second)
        return false;
    else
        return p1.first < p2.first; // 데이터가 같으면, 인덱스가 작은 게 less -> stable sort
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num, max = 0;
    cin >> N;
    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; i++) {
        cin >> num;
        v[i] = make_pair(i, num);
    }
       
    sort(v.begin(), v.end(), less_cmp);

    for (int i = 0; i < N; i++) {
        int dist = v[i].first - i;
        if (dist > max)
            max = dist;
    }
    cout << max + 1 << "\n";

    return 0;
}