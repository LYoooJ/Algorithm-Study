#include <iostream>
#include <stack>
#include <string>

#define PUSH "push"
#define POP "pop"
#define SIZE "size"
#define EMPTY "empty"
#define TOP "top"

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string cmd;
    int num;
    stack<int> stk;

    for (int i = 0; i < N; i++) {
        cin >> cmd;
        if (!cmd.compare(PUSH)) {
            cin >> num;
            stk.push(num);
        }
        else if (!cmd.compare(POP)) {
            if (stk.empty()) {
                cout << -1 << "\n";
            } 
            else {
                cout << stk.top() << "\n";
                stk.pop();
            }
        }
        else if (!cmd.compare(SIZE)) {
            cout << stk.size() << "\n";
        }
        else if (!cmd.compare(EMPTY)) {
            cout << stk.empty() << "\n";
        }
        else if (!cmd.compare(TOP)) {
            if (stk.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << stk.top() << "\n";
            }
        }
    }

    return 0;
}