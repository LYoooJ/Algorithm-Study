#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<vector<int>>& A, vector<int>& visited, int src);
void bfs(vector<vector<int>>& A, vector<int>& visited, int src);

static queue<int> q;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V, u, v;
    cin >> N >> M >> V;
    vector<vector<int>> A1(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> A2(N + 1, vector<int>(N + 1, 0));
    vector<int> visited1(N + 1, 0);
    vector<int> visited2(N + 1, 0);

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        A1[u][v] = 1;
        A1[v][u] = 1;
        A2[u][v] = 1;
        A2[v][u] = 1;
    }
    dfs(A1, visited1, V);
    cout << "\n";

    bfs(A2, visited2, V);
    cout << "\n";

    return 0;
}

void dfs(vector<vector<int>>& A, vector<int>& visited, int src) {
    visited[src] = 1;
    cout << src << " ";
    for (int i = 1; i < A[src].size(); i++) {
        if (A[src][i] && !visited[i])
            dfs(A, visited, i);
    }
}

void bfs(vector<vector<int>>& A, vector<int>& visited, int src) {
    q.push(src);
    visited[src] = 1;
    cout << src << " ";

    while (!q.empty()) {
        src = q.front();
        q.pop();
        for (int i = 1; i < A[src].size(); i++) {
            if (A[src][i] && !visited[i]) {
                visited[i] = 1;
                cout << i << " ";
                q.push(i);
            }
        }
    }
}