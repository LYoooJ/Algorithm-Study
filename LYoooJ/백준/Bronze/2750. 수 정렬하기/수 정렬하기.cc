#include <iostream>

using namespace std;

int main(void) {
    int numbers[1000] = {};
    int N, num, temp;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        numbers[i] = num;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < N; i++)
        cout << numbers[i] << "\n";

    return 0;
}