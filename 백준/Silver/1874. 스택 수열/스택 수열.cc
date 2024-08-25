#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, sequence, num = 1;
    stack<int> stk;
    vector<char> v;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> sequence;
        if (num <= sequence) {
            while (num <= sequence) {
                stk.push(num++);
                v.push_back('+');
            }
            stk.pop();
            v.push_back('-');
        }
        else {
            if (stk.top() == sequence) {
                stk.pop();
                v.push_back('-');
            }
            else {
                cout << "NO" << "\n";
                return 0;
            }
        }
    }

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "\n";

    return 0;
}