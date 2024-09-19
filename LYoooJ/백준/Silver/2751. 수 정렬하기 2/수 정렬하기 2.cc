#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int>& v, vector<int>& temp, int start, int end);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> v(N, 0);
    vector<int> temp(N, 0);
    
    for (int i = 0; i < N; i++)
        cin >> v[i];

    merge_sort(v, temp, 0, N - 1);

    for (int i = 0; i < N; i++)
        cout << v[i] << "\n";

    return 0;
}

void merge_sort(vector<int>& v, vector<int>& temp, int start, int end) {
    if (end - start < 1)
        return;

    int M = (start + end) / 2;
    merge_sort(v, temp, start, M);
    merge_sort(v, temp, M + 1, end);

    int left = start, right = M + 1, idx = start;

    while (left <= M && right <= end) {
        if (v[left] < v[right])
            temp[idx++] = v[left++];
        else
            temp[idx++] = v[right++];
    }

    while (left <= M) {
        temp[idx++] = v[left++];
    }

    while (right <= end) {
        temp[idx++] = v[right++];
    }

    for (int i = start; i <= end; i++)
        v[i] = temp[i];
}