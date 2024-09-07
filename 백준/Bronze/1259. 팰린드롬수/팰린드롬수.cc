#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string number;

    while (true) {
        cin >> number;
        if (!number.compare("0"))
            break;
        int left = 0, right = number.size() - 1;
        bool flag = true;

        while (left < right) {
            if (number[left++] != number[right--]) {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}