#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(string& s1, string& s2) {
    if (s1.size() < s2.size())
        return true;
    else if (s1.size() > s2.size())
        return false;
    else
        return s1 < s2;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string word;
    vector<string> v;
    map<string, int> m;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> word;
        if (m.count(word) == 0) {
            v.push_back(word);
            m[word] += 1;
        }
    }

    sort(v.begin(), v.end(), cmp);
 
    for (int i = 0; i < m.size(); i++) {
        cout << v[i] << "\n";
    }

    return 0;
}