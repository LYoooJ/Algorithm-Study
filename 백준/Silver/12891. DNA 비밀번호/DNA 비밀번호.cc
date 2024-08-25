#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string dna;
    map<char, int> count;

    int password_count = 0;
    int min_A, min_C, min_G, min_T;
    int whole_len, sub_len, start, end;

    cin >> whole_len >> sub_len;
    start = 0, end = sub_len - 1;

    cin >> dna;
    for (int i = 0; i < sub_len; i++)
        count[dna[i]] += 1;

    cin >> min_A >> min_C >> min_G >> min_T;

    while (end < whole_len) {
        if (count['A'] >= min_A && count['C'] >= min_C && count['G'] >= min_G && count['T'] >= min_T)
            password_count++;

        count[dna[start]] -= 1;
        start++;
        end++;
        count[dna[end]] += 1;
    }
    cout << password_count << "\n";

    return 0;
}