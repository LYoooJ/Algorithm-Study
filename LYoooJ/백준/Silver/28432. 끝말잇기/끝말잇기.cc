#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool first_char_check(string word, string prior, int idx);
bool last_char_check(string word, string following, int idx);


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int idx = 0, N, M;
    string word;

    cin >> N;
    vector<string> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        if (!v[i].compare("?"))
            idx = i;
    }

    cin >> M;
    if (N == 1) {
        cin >> word;
        cout << word;
    }
    else {
        for (int i = 0; i < M; i++) {
            cin >> word;
            if ((idx == 0 && last_char_check(word, v[idx + 1], idx)) || (idx == N - 1 && first_char_check(word, v[idx - 1], idx)) || (first_char_check(word, v[idx - 1], idx) && last_char_check(word, v[idx + 1], idx))) {
                if (find(v.begin(), v.end(), word) == v.end()) {
                    cout << word;
                    break;
                }
            }
        }    
    }

    return 0;
}

bool first_char_check(string word, string prior, int idx) {
    return  word[0] == prior[prior.size() - 1];
}

bool last_char_check(string word, string following, int idx) {
    return word[word.size() - 1] == following[0];
}