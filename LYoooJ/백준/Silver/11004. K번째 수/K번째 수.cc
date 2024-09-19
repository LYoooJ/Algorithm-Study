#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int>& v, int low, int high, int K);
void swap_element(vector<int>& v, int a, int b);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> v(N, 0);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    quick_sort(v, 0, N - 1, K);
    cout << v[K - 1] << "\n";

    return 0;
}

void quick_sort(vector<int>& v, int left, int right, int K) {
    if (left >= right)
        return;
    int p;

    if (left + 1 == right) {
        if (v[left] > v[right]) 
            swap_element(v, left, right);
        p = right;
    }
    else {
        int pivot_idx = (left + right) / 2;
        int pivot = v[pivot_idx];
        swap_element(v, left, pivot_idx);

        int low = left + 1;
        int high = right;

        while (low <= high) {
            while (low <= right && v[low] < pivot)
                low++;
            while (high >= left + 1 && v[high] > pivot)
                high--;
            if (low < high)
                swap_element(v, low++, high--);
            else
                break;
        }
        swap_element(v, left, high);  
        p = high;
    }

    if (p == K - 1)
        return;
    else if (p > K - 1)
        quick_sort(v, left, p - 1, K);
    else
        quick_sort(v, p + 1, right, K);
}

void swap_element(vector<int>& v, int a, int b) {
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}