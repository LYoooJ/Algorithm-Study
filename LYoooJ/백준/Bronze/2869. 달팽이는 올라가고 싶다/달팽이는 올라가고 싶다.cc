#include <iostream>

using namespace std;

int main(void) {
    int A, B, V;
    int day = 0, h = 0;

    cin >> A >> B >> V;

    int min = V % (A - B) == 0 ? V / (A - B) : V / (A - B) + 1;

    while ((A - B) * (min - 1)+ A >= V)
        min--;

    cout << min + 1;

    return 0;
}