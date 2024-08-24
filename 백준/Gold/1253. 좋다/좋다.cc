#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, count = 0;
    cin >> N;

    vector<int> numbers(N);
    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    sort(numbers.begin(), numbers.end());

    for (int i = N - 1; i >= 0; i--) {
        int M = numbers[i];
        int start = 0, end = N - 1;
        while (start < end) {
            if (start == i) {
                start++;
                continue;
            }
            else if (end == i) {
                end--;
                continue;
            }

            if (numbers[start] + numbers[end] < M) {
                start++;
            }
            else if (numbers[start] + numbers[end] > M) {
                end--;
            }  
            else {
                count++;
                break;
            }
        }
    }
    cout << count << "\n";

    return 0;
}