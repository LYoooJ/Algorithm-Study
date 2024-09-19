#include <iostream>
#include <vector>

using namespace std;

void dfs(int src, vector<int>& visited, vector<vector<int>>& A);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, u, v;
    int num = 0;
    cin >> N >> M;

    vector<vector<int>> A(N + 1, vector<int>(N + 1, 0));
    vector<int> visited(N + 1, 0);

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        A[u][v] = 1;
        A[v][u] = 1;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i, visited, A);
            num++;
        }
    }
    cout << num << "\n";

    return 0;
}

void dfs(int src, vector<int>& visited, vector<vector<int>>& A) {
    visited[src] = 1;
    for (int c = 1; c < A[src].size(); c++) {
        if (A[src][c] && !visited[c]) {
            dfs(c, visited, A);
        }
    }
}