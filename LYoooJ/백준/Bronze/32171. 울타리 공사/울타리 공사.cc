#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int N;
    int a, b, c, d, x1, x2, y1, y2;
    cin >> N;
    
    cin >> x1 >> y1 >> x2 >> y2;
    cout << 2 * (x2 - x1) + 2 * (y2 - y1) << "\n";
    for (int i = 1; i < N; i++) {
        cin >> a >> b >> c >> d;
        x1 = min(x1, a);
        y1 = min(y1, b);
        x2 = max(x2, c);
        y2 = max(y2, d);
        cout << 2 * (x2 - x1) + 2 * (y2 - y1) << "\n";
    }
    
    return 0;
}