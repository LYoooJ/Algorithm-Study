#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    int N, num;
    queue<int> q;

    cin >> N;
    for (int i = 1; i <= N; i++)
        q.push(i);

    while (q.size() > 1) {
        q.pop();
        num = q.front();
        q.pop();
        q.push(num);
    }
    cout << q.front() << "\n";

    return 0;
}