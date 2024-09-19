#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int N, size;
    string name, cmp;

    cin >> N;
    cin >> name;
    size = name.size();

    for (int i = 1; i < N; i++) {
        cin >> cmp;
        for (int j = 0; j < size; j++) {
            if (name[j] != cmp[j])
                name[j] = '?';
        }
    }

    cout << name;

    return 0;
}