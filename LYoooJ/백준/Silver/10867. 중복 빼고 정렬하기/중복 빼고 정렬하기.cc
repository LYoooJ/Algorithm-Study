#include <iostream>
#include <set>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    set<int> s;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;
        s.insert(num);
    }

    for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << " ";
    }

    return 0;
}