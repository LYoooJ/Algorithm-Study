#include <iostream>

using namespace std;

bool is_prime(int num);
void dfs(int num, int len, int N);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int prime_n[4] = { 2, 3, 5, 7 };
    int N;
    cin >> N;

    for (int i = 0; i < 4; i++) {
        dfs(prime_n[i], 1, N);
    }
    return 0;
}

bool is_prime(int num) {
    for (int i = 2; i < num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void dfs(int num, int len, int N) {
    int n[5] = { 1, 3, 5, 7, 9 };
    if (!is_prime(num)) {
        return;
    }
    else {
        if (len == N) {
            cout << num << "\n";
            return;
        }
        else {
            for (int i = 0; i < 5; i++) {
                int new_num = 10 * num + n[i];
                dfs(new_num, len + 1, N);
            }
        }
    }
}
