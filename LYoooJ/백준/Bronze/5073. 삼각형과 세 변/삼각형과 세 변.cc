#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    set<int> s;
    string str[3] = { "Equilateral\n", "Isosceles\n", "Scalene\n" };

    while (true) {
        cin >> a >> b >> c;
        s.insert(a);
        s.insert(b);
        s.insert(c);

        set<int>::iterator iter = s.end();
        int max = *(--iter);
        if (!a && !b && !c)
            break;

        if (a + b + c - 2 * max <= 0)
            cout << "Invalid\n";
        else {
            cout << str[s.size() - 1];
        }
        s.clear();
    }

    return 0;
}