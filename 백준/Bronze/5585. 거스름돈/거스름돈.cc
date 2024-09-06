#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int money, num = 0, i = 0;
    int cash[6] = { 500, 100, 50, 10, 5, 1 };
    cin >> money;
    money = 1000 - money;

    while (money > 0) {
        if (money >= cash[i]) {
            money -= cash[i];
            num++;
        }
        else {
            i++;
        }
    }
    cout << num;

    return 0;
}