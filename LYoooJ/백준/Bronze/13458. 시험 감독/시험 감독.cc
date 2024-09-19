#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, B, C;
    long total = 0;
    cin >> N;
    vector<int> v(N);
     
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    cin >> B >> C;

    for (int i = 0; i < N; i++) {
        v[i] -= B;
        total++;
        if (v[i] > 0)
            total += (v[i] % C == 0 ? v[i] / C : v[i] / C + 1);
    }
    cout << total << "\n";

    return 0;
}