#include <iostream>
#include <stack>

using namespace std;

void stack_clear(stack<char>& s);

int main(void) {
    int N;
    string ps;
    stack<char> stk;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> ps;
        for (int j = 0; j < ps.size(); j++) {
            if (!stk.empty() && stk.top() != ps[j] && stk.top() == '(')
                stk.pop();
            else
                stk.push(ps[j]);
        }
        if (stk.empty()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
            stack_clear(stk);
        }
    }
    return 0;
}

void stack_clear(stack<char>& s) {
    while (!s.empty())
        s.pop();
}