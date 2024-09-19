#include <iostream>
#include <map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string word;
    map<char, int> m;
    char alphabets[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    cin >> word;
    for (int i = 0; i < word.size(); i++) {
        if (m.count(word[i]) == 0)
            m[word[i]] = i;
        else
            continue;
    }
    
    for (int i = 0; i < 26; i++) {
        if (m.count(alphabets[i]) == 0) {
            cout << -1 << " ";
        }
        else {
            cout << m[alphabets[i]]<< " ";
        }
    }

    return 0;
}