#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int start = 1, end = 1, count = 0;
    int sum = 1;
    int N;
    cin >> N;
    
    while (start <= N) {
        if (sum < N) {
            end++;
            sum += end;
        }
        else if (sum > N) {
            sum -= start;
            start++;
        } 
        else {
            count++;
            sum -= start;
            start++;
        }
    }
    cout << count << "\n";

    return 0;
}