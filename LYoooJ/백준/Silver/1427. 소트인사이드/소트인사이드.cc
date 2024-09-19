#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    string number;
    cin >> number;

    sort(number.begin(), number.end(), greater<>());
    cout << number;

    return 0;
}