#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(void) {
    int N, size;
    string name[50];
    list<int> lt;
    list<int> diff;

    cin >> N;

    for (int i = 0; i < N; i++) 
        cin >> name[i];
    size = name[0].size();

    for (int i = 0; i < size; i++)
        lt.push_back(i);

    for (int i = 1; i < N; i++) {
        for (list<int>::iterator iter = lt.begin(); iter != lt.end(); ) {
            int idx = *iter;
            if (name[i - 1][idx] != name[i][idx]) {
                iter++;
                lt.remove(idx);
                diff.push_back(idx);
            }
            else {
                iter++;
            }
        }
    }
    
    for (list<int>::iterator iter = diff.begin(); iter != diff.end(); iter++) {
        name[0][*iter] = '?';
    }
    cout << name[0];

    return 0;
}