#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string name;
    int N, M;
    map<string, int> m;
    set<string> s;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> name;
        m[name] += 1;
    }
        
    for (int i = 0; i < M; i++) {
        cin >> name;
        if (m.count(name) != 0) {
            s.insert(name);
        }
    }

    cout << s.size() << "\n";
    for (set<string>::iterator iter = s.begin(); iter != s.end(); iter++)
        cout << *iter << "\n";

    return 0;
}